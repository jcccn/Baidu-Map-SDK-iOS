/*
 *  BMKUserLocation.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "BMKAnnotation.h"

@class CLLocation;
@class BMKUserLocationInternal;

NS_CLASS_AVAILABLE(__MAC_NA, 3_0)
/// 定位服务Delegate,调用startUserLocationService定位成功后，用此Delegate来获取定位数据
@protocol BMKUserLocationDelegate <NSObject>
@optional
/**
 *调用startUserLocationService定位成功后，会调用此函数
 *@param userLoc 我的位置坐标
 */
- (void)viewDidGetLocatingUser:(CLLocationCoordinate2D)userLoc;
@end

/// 定位信息类
@interface BMKUserLocation : NSObject <BMKAnnotation> 
/// 位置更新状态，如果正在更新位置信息，则该值为YES
@property (readonly, nonatomic, getter=isUpdating) BOOL updating;

/// 位置信息，如果BMKMapView的showsUserLocation为NO，或者尚未定位成功，则该值为nil
@property (readonly, nonatomic) CLLocation *location;

/// 定位标注点要显示的标题信息
@property (retain, nonatomic) NSString *title;

/// 定位标注点要显示的子标题信息.
@property (retain, nonatomic) NSString *subtitle;

/// 定位服务Delegate,调用startUserLocationService定位成功后，用此Delegate来获取定位数据
@property (nonatomic, retain) id<BMKUserLocationDelegate> delegate;
/**
 *打开定位服务
 */
-(void)startUserLocationService;
/**
 *关闭定位服务
 */
-(void)stopUserLocationService;
@end


