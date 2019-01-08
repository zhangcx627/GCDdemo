//
//  GCDManager.h
//  GCD
//
//  Created by chenxu on 2018/12/27.
//  Copyright © 2018年 chenxu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GCDManager : NSObject

+(instancetype)sharedInstance;

@property (nonatomic, assign) NSInteger ticketSurplusCount;

@property (nonatomic, strong) dispatch_semaphore_t semaphoreLock;

@property (nonatomic, strong) NSLock *lock;

@end

NS_ASSUME_NONNULL_END
