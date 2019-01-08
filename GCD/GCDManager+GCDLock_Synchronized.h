//
//  GCDManager+GCDLock_Synchronized.h
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
@implementation GCDManager (GCDLock_Synchronized)

-(void)GCDLock_Synchronized {
    NSLog(@"GCDLock_Synchronized");
    self.ticketSurplusCount = 10;
    dispatch_queue_t queue1 = dispatch_queue_create("com.GCD.SaleBeijing.queue", DISPATCH_QUEUE_SERIAL);
    dispatch_queue_t queue2 = dispatch_queue_create("com.GCD.SaleShanghai.queue", DISPATCH_QUEUE_SERIAL);
    __weak typeof(self) weakSelf = self;
    dispatch_async(queue1, ^{
        [weakSelf saleTicketSafe];
    });
    dispatch_async(queue2, ^{
        [weakSelf saleTicketSafe];
    });
}


-(void) saleTicketSafe {
    while (1) {
        //加锁
        @synchronized (self) {
            if (self.ticketSurplusCount > 0) {
                self.ticketSurplusCount = self.ticketSurplusCount - 1;
                NSLog(@"剩余票数:%ld 窗口:%@", (long)self.ticketSurplusCount, [NSThread currentThread]);
                [NSThread sleepForTimeInterval:0.1];
            } else {
                NSLog(@"所有火车票均售完");
                break;
            }
        }
    }
}
@end
