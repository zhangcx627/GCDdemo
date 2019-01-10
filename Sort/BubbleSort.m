//
//  BubbleSort.m
//  Sort
//
//  Created by chenxu on 2019/1/9.
//  Copyright © 2019年 chenxu. All rights reserved.
//

#import "BubbleSort.h"

@implementation BubbleSort

-(void)BubbleSort {
    NSMutableArray *arr = [NSMutableArray arrayWithObjects:@"18",@"28",@"8",@"58",@"38", nil];
    NSLog(@"排序之前:%@", arr);
    NSInteger m = 0;
    for (int i = 0; i < arr.count - 1; i++) {
        for (int j = 0; j < arr.count - 1 - i; j++) {
            NSLog(@"已经执行循环：%ld", (long)m++);
            if([arr[j] intValue] > [arr[j+1] intValue]) {
                int temp = [arr[j] intValue];
                arr[j] = arr[j+1];
                arr[j+1] = [NSString stringWithFormat:@"%d", temp];
            }
        }
    }
    NSLog(@"排序之后：%@",arr);
}

-(void)ChooseSort {

}


@end
