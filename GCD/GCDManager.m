//
//  GCDManager.m
//  GCD
//
//  Created by chenxu on 2018/12/27.
//  Copyright © 2018年 chenxu. All rights reserved.
//

#import "GCDManager.h"

@interface GCDManager()

@end

static GCDManager *manager = nil;

@implementation GCDManager

+(instancetype)allocWithZone:(struct _NSZone *)zone
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (manager == nil) {
            manager = [super allocWithZone:zone];
        }
    });
    return manager;
}

+(instancetype)sharedInstance {
    return [[GCDManager alloc] init];
}

// 为了严谨，也要重写copyWithZone 和 mutableCopyWithZone
-(id)copyWithZone:(NSZone *)zone
{
    return manager;
}

-(id)mutableCopyWithZone:(NSZone *)zone
{
    return manager;
}


@end
