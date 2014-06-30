/*
 *  BMKPoiSearchOption.h
 *  BMapKit
 *
 *  Copyright 2013 Baidu Inc. All rights reserved.
 *
 */

#import "BMKTypes.h"
#import "BMKRouteSearchType.h"
/// 路线查询基础信息类
@interface BaseRoutePlanOption : NSObject
{
    BMKPlanNode        *_from;
    BMKPlanNode        *_to;
}
///检索的起点，可通过关键字、坐标两种方式指定
@property (nonatomic, retain) BMKPlanNode *from;
///检索的终点，可通过关键字、坐标两种方式指定
@property (nonatomic, retain) BMKPlanNode *to;
@end
/// 步行查询基础信息类
@interface BMKWalkingRoutePlanOption : BaseRoutePlanOption
{

}
@end
/// 驾车查询基础信息类
@interface BMKDrivingRoutePlanOption : BaseRoutePlanOption
{
    NSArray*   _wayPointsArray;
    BMKDrivingPolicy _drivingPolicy;
}
@property (nonatomic, retain) NSArray  *wayPointsArray;
///驾车检索策略
@property (nonatomic) BMKDrivingPolicy drivingPolicy;



@end
/// 公交查询基础信息类
@interface BMKTransitRoutePlanOption : BaseRoutePlanOption
{
    NSString*               _city;
    BMKTransitPolicy        _transitPolicy;
}
///城市名，用于在哪个城市内进行检索
@property (nonatomic, retain) NSString *city;
///公交检索策略
@property (nonatomic) BMKTransitPolicy transitPolicy;

@end



