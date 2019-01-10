//
//  TableViewController.m
//  Sort
//
//  Created by chenxu on 2019/1/9.
//  Copyright © 2019年 chenxu. All rights reserved.
//

#import "TableViewController.h"
#import "BubbleSort.h"





@interface TableViewController ()

@property (strong, nonatomic) NSMutableArray *cellArray;

@end

@implementation TableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.cellArray = [NSMutableArray arrayWithObjects:@"冒泡", nil];

    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"SortCell"];

}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.cellArray.count;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"SortCell" forIndexPath:indexPath];
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"SortCell"];
    }
    cell.textLabel.text = self.cellArray[indexPath.row];

    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if (indexPath.row == 0) {
        BubbleSort *bubble = [[BubbleSort alloc]init];
        [bubble BubbleSort];
    }
}


@end
