/*
 *  BMKNavigation.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */
#import <UIKit/UIKit.h>
#import "BMKRouteSearchType.h"
//定义调启导航的两种类型
typedef enum
{
    NAVI_TYPE_NATIVE = 0,//客户端导航
    NAVI_TYPE_WEB,//web导航
} NAVI_TYPE;

///此类管理调启导航时传入的参数
@interface NaviPara : NSObject
{
	BMKPlanNode* _startPoint;
	BMKPlanNode* _endPoint;
	NAVI_TYPE _naviType;
    NSString* _appScheme;
    NSString* _appName;
}
///起点
@property (nonatomic, retain) BMKPlanNode* startPoint;
///终点
@property (nonatomic, retain) BMKPlanNode* endPoint;
///导航类型
@property (nonatomic, assign) NAVI_TYPE naviType;
///应用返回scheme
@property (nonatomic, retain) NSString* appScheme;
///应用名称
@property (nonatomic, retain) NSString* appName;


@end

///主引擎类
@interface BMKNavigation : NSObject

/**
*启动导航
*@param para 调启导航时传入得参数
*/
+ (void)openBaiduMapNavigation:(NaviPara*)para;


@end


