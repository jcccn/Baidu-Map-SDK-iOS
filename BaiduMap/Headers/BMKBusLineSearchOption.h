/*
 *  BMKBusLineSearchOption.h
 *  BMapKit
 *
 *  Copyright 2014 Baidu Inc. All rights reserved.
 *
 */

/// 公交线路检索信息类
@interface BMKBusLineSearchOption : NSObject
{
    NSString        *_city;
    NSString        *_busLineUid;
}
///城市名
@property (nonatomic, retain) NSString *city;
///公交线路的uid
@property (nonatomic, retain) NSString *busLineUid;

@end

