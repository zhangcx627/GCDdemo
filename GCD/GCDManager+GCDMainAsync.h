//
//  GCDManager+GCDMainAsync.h
//  GCD
//
//  Created by chenxu on 2018/12/28.
//  Copyright © 2018年 chenxu. All rights reserved.
//

#import "GCDManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface GCDManager ()

@end

NS_ASSUME_NONNULL_END
@implementation GCDManager (GCDMainAsync)

-(void)GCDMainAsync {
    //死锁
    NSLog(@"GCDMainSync");
    dispatch_queue_t queue = dispatch_get_main_queue();
    dispatch_async(queue, ^{
        NSLog(@"queue 1");
        [NSThread sleepForTimeInterval:1];
        NSLog(@"queue 2");
    });
    dispatch_async(queue, ^{
        NSLog(@"queue 3");
        [NSThread sleepForTimeInterval:1];
        NSLog(@"queue 4");
    });
}

@end
