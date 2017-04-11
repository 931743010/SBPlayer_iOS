//
//  SBView.h
//  SBPlayer
//
//  Created by sycf_ios on 2017/4/10.
//  Copyright © 2017年 shibiao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "SBCommonHeader.h"
#import "SBControlView.h"
#import "SBPauseOrPlayView.h"
//填充模式枚举值
typedef NS_ENUM(NSInteger,SBLayerVideoGravity){
    SBLayerVideoGravityResizeAspect,
    SBLayerVideoGravityResizeAspectFill,
    SBLayerVideoGravityResize,
};
//播放状态枚举值
typedef NS_ENUM(NSInteger,SBPlayerStatus){
    SBPlayerStatusFailed,
    SBPlayerStatusReadyToPlay,
    SBPlayerStatusUnknown,
    SBPlayerStatusBuffering,
    SBPlayerStatusPlaying,
    SBPlayerStatusStopped,
};
@interface SBPlayer : UIView<SBControlViewDelegate,SBPauseOrPlayViewDelegate>{
    id playbackTimerObserver;
}
@property (nonatomic,strong) AVPlayer *player;
@property (nonatomic,strong) AVPlayerItem *item;
//播放器Playback Rate
@property (nonatomic,assign) CGFloat rate;
//播放状态
@property (nonatomic,assign,readonly) SBPlayerStatus status;
//videoGravity设置屏幕填充模式，（只写）
@property (nonatomic,assign) SBLayerVideoGravity mode;
//是否正在播放
@property (nonatomic,assign,readonly) BOOL isPlaying;
//设置标题
@property (nonatomic,copy) NSString *title;

//与url初始化
-(instancetype)initWithUrl:(NSURL *)url;
//将播放url放入资产中初始化播放器
-(void)assetWithURL:(NSURL *)url;
//播放
-(void)play;
//暂停
-(void)pause;
//停止
-(void)stop;

@end