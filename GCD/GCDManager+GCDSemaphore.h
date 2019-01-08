//
//  GCDManager+GCDSemaphore.h
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

@implementation GCDManager (GCDSemaphore)

-(void)GCDSemaphore {
    NSLog(@"GCDSemaphore");

    dispatch_queue_t workConcurrentQueue = dispatch_queue_create("com.GCD.Concurrent.queue", DISPATCH_QUEUE_CONCURRENT);
    dispatch_queue_t serialQueue = dispatch_queue_create("com.GCD.serial.queue",DISPATCH_QUEUE_SERIAL);
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(1);

    //    for (NSInteger i = 0; i < 10; i++) {
    //        dispatch_async(serialQueue, ^{
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    dispatch_async(workConcurrentQueue, ^{
        sleep(1);
        NSLog(@"thread-info1:%@结束执行任务",[NSThread currentThread]);
        dispatch_semaphore_signal(semaphore);
    });
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    NSLog(@"1");
    dispatch_async(workConcurrentQueue, ^{
        sleep(1);
        NSLog(@"thread-info2:%@结束执行任务",[NSThread currentThread]);
        dispatch_semaphore_signal(semaphore);
    });
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    NSLog(@"2");
    dispatch_async(workConcurrentQueue, ^{
        sleep(1);
        NSLog(@"thread-info3:%@结束执行任务",[NSThread currentThread]);
        dispatch_semaphore_signal(semaphore);
    });
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    NSLog(@"3");
    dispatch_async(workConcurrentQueue, ^{
        sleep(1);
        NSLog(@"thread-info4:%@结束执行任务",[NSThread currentThread]);
        dispatch_semaphore_signal(semaphore);
    });
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    NSLog(@"4");
    dispatch_async(workConcurrentQueue, ^{
        sleep(1);
        NSLog(@"thread-info5:%@结束执行任务",[NSThread currentThread]);
        dispatch_semaphore_signal(semaphore);
    });
    //        });
    //    }
    NSLog(@"主线程...!");
}

@end
