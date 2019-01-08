//
//  GCDManager+GCDSerial.h
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

@implementation GCDManager (GCDSerial)

-(void)GCDSerial {
    NSLog(@"GCDSerial");
    dispatch_queue_t queue = dispatch_queue_create("com.GCD.GCDSerial.queue", DISPATCH_QUEUE_CONCURRENT);
    dispatch_async(queue, ^{
        sleep(2);
        NSLog(@"queue 1");
    });
    dispatch_async(queue, ^{
        sleep(1);
        NSLog(@"queue 2");
    });
    dispatch_sync(queue, ^{
        sleep(1.6);
        NSLog(@"sync queue 3");
    });
    dispatch_sync(queue, ^{
        sleep(1.5);
        NSLog(@"sync queue 4");
    });
    dispatch_async(queue, ^{
        sleep(1);
        NSLog(@"queue 5");
    });

}

@end
