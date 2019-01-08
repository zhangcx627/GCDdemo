//
//  GCDManager+GCDPriority.h
//  GCD
//
//  Created by chenxu on 2019/1/2.
//  Copyright © 2019年 chenxu. All rights reserved.
//

#import "GCDManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface GCDManager ()

@end

NS_ASSUME_NONNULL_END

@implementation GCDManager (GCDPriority)

-(void)GCDPriority {
    //不论怎么样 queue2 都是在最后执行
    NSLog(@"GCDPriority");
    dispatch_queue_t queue1 = dispatch_queue_create("com.GCD.SaleBeijing.queue", dispatch_queue_attr_make_with_qos_class(DISPATCH_QUEUE_CONCURRENT, QOS_CLASS_USER_INTERACTIVE, 0));
    dispatch_queue_t queue2 = dispatch_queue_create("com.GCD.SaleShanghai.queue", DISPATCH_QUEUE_CONCURRENT);
    dispatch_async(queue1, ^{
        sleep(1);
        NSLog(@"queue3: %@",[NSThread currentThread]);
    });
    dispatch_async(queue2, ^{
        sleep(1);
        NSLog(@"queue2: %@",[NSThread currentThread]);
    });
    dispatch_async(queue1, ^{
        sleep(1);
        NSLog(@"queue1: %@",[NSThread currentThread]);
    });

}

-(void)logThread {

}

@end
