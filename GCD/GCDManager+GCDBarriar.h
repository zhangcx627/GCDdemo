//
//  GCDManager+GCDBarriar.h
//  GCD
//
//  Created by chenxu on 2019/1/8.
//  Copyright © 2019年 chenxu. All rights reserved.
//

#import "GCDManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface GCDManager ()

@end

NS_ASSUME_NONNULL_END
@implementation GCDManager (GCDBarriar)

-(void)GCDBarriar {
    //dispatch_barrier_async 并行队列中等待前边线程执行完成后再执行  然后队列恢复原有执行状态继续并行
    //只在DISPATCH_QUEUE_CONCURRENT生效  在DISPATCH_QUEUE_SERIAL中和dispatch_sync 效果相同
    NSLog(@"GCDBarriar");
    dispatch_queue_t queue = dispatch_queue_create("com.GCD.GCDBarriar.queue", DISPATCH_QUEUE_CONCURRENT);
    dispatch_sync(queue, ^{
//        sleep(1);
        NSLog(@"queue3: %@",[NSThread currentThread]);
    });
    dispatch_async(queue, ^{
//        sleep(1);
        NSLog(@"queue2: %@",[NSThread currentThread]);
    });
    dispatch_barrier_async(queue, ^(){
        sleep(2);
        NSLog(@"dispatch-barrier");
    });
    dispatch_async(queue, ^{
//        sleep(1);
        NSLog(@"queue1: %@",[NSThread currentThread]);
    });

}

@end
