//
//  TableViewController.m
//  GCD
//
//  Created by chenxu on 2018/12/27.
//  Copyright © 2018年 chenxu. All rights reserved.
//

#import "TableViewController.h"
#import "GCDManager.h"
#import "GCDManager+GCDSerial.h"
#import "GCDManager+GCDConcurrent.h"
#import "GCDManager+GCDSemaphore.h"
#import "GCDManager+GCDMainSync.h"
#import "GCDManager+GCDMainAsync.h"
#import "GCDManager+GCDGroup.h"
#import "GCDManager+GCDLock_Semaphore.h"
#import "GCDManager+GCDLock_Synchronized.h"
#import "GCDManager+GCDLock_NSLock.h"
#import "GCDManager+GCDPriority.h"





@interface TableViewController ()

@property (strong, nonatomic) NSMutableArray *cellArray;

@end

@implementation TableViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.cellArray = [NSMutableArray arrayWithObjects:@"串行",@"并行",@"信号量",@"错误卡主线程",@"主线程调用异步",@"GCDGroup",@"GCDGroup Use Enter & Leave", @"GCDLock Use Semaphore", @"GCDLock Use Synchronized",@"GCDLock Use NSLock",@"优先级", nil];

    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"GCDCell"];
}

#pragma mark - Table view data source
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.cellArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"GCDCell" forIndexPath:indexPath];
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"GCDCell"];
    }
    cell.textLabel.text = self.cellArray[indexPath.row];

    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if (indexPath.row == 0) {
        //GCD 串行
        [[GCDManager sharedInstance] GCDSerial];
    } else if (indexPath.row == 1) {
        //GCD 并行
        [[GCDManager sharedInstance] GCDConcurrent];
    } else if (indexPath.row == 2) {
        [[GCDManager sharedInstance] GCDSemaphore];
    } else if (indexPath.row == 3) {
        [[GCDManager sharedInstance] GCDMainSync];
    } else if (indexPath.row == 4) {
         [[GCDManager sharedInstance] GCDMainAsync];
    } else if (indexPath.row == 5) {
        [[GCDManager sharedInstance] GCDGroup];
    } else if (indexPath.row == 6) {
        [[GCDManager sharedInstance] GCDGroup1];
    } else if (indexPath.row == 7) {
        [[GCDManager sharedInstance] GCDLock_Semaphore];
    } else if (indexPath.row == 8) {
        [[GCDManager sharedInstance] GCDLock_Synchronized];
    } else if (indexPath.row == 9) {
        [[GCDManager sharedInstance] GCDLock_NSLock];
    } else if (indexPath.row == 10) {
        [[GCDManager sharedInstance] GCDPriority];
    }
}



@end
