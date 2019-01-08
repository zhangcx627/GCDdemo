//
//  GCDManager+GCDConcurrent.h
//  GCD
//
//  Created by chenxu on 2018/12/27.
//  Copyright © 2018年 chenxu. All rights reserved.
//

#import "GCDManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface GCDManager ()

@end

NS_ASSUME_NONNULL_END

@implementation GCDManager (GCDConcurrent)

-(void)GCDConcurrent {
    NSLog(@"GCDConcurrent");
    dispatch_queue_t queue = dispatch_queue_create("com.GCD.GCDSerial.queue", DISPATCH_QUEUE_CONCURRENT);
    
    for (int i = 0; i< 20;i++){
        // 10个异步
        dispatch_async(queue, ^{
            sleep(1);
            NSLog(@"%@--%d",[NSThread currentThread], i);
        });
    }
}

@end
