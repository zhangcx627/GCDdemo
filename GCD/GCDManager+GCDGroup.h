//
//  GCDManager+GCDGroup.h
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
@implementation GCDManager (GCDGroup)

-(void)GCDGroup {
    NSLog(@"GCDGroup");
    //全局的队列
    dispatch_queue_t globalQueue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    //自定的队列
    dispatch_queue_t selfQueue = dispatch_queue_create("com.GCD.GCDGroup.queue", 0);
    dispatch_group_t group = dispatch_group_create();
    dispatch_group_async(group, globalQueue, ^{
        sleep(2);
        NSLog(@"run group 1:%@",[NSThread currentThread]);
    });
    dispatch_group_async(group, selfQueue, ^{
        sleep(1);
        NSLog(@"run group 2:%@", [NSThread currentThread]);
    });
    dispatch_group_async(group, selfQueue, ^{
        sleep(2);
        NSLog(@"run group 3:%@",[NSThread currentThread]);
    });

    dispatch_group_notify(group, dispatch_get_main_queue(), ^{
        NSLog(@"run group 4:%@", [NSThread currentThread]);
    });
}

-(void)GCDGroup1 {
    dispatch_queue_t queue = dispatch_queue_create("com.GCD.GCDGroup.queue", 0);

    dispatch_group_t group = dispatch_group_create();
    //必须先enter 才能进入到group 然后结束后leave
    //如果没有enter 去leave 的话 会造成crash
    //相反如果只enter 而没有leave 的话 group notify 是不会去执行的。
    dispatch_group_enter(group);
    dispatch_async(queue, ^{
        sleep(1);
        NSLog(@"run group 1:%@", [NSThread currentThread]);
        dispatch_group_leave(group);
    });

    dispatch_group_enter(group);
    dispatch_async(queue, ^{
        sleep(2);
        NSLog(@"run group 2:%@", [NSThread currentThread]);
        dispatch_group_leave(group);
    });

    dispatch_group_enter(group);
    dispatch_async(queue, ^{
        sleep(3);
        NSLog(@"run group 3:%@", [NSThread currentThread]);
        dispatch_group_leave(group);
    });

    dispatch_group_notify(group, dispatch_get_main_queue(), ^{
        NSLog(@"run group 4:%@", [NSThread currentThread]);
    });
}

@end
