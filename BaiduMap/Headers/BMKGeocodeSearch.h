/*
 *  BMKGeocodeSearch.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import "BMKPoiSearchType.h"
#import "BMKGeocodeSearchOption.h"
#import "BMKGeocodeType.h"

@protocol BMKGeocodeSearchDelegate;
///geo搜索服务
@interface BMKGeocodeSearch : NSObject
/// 检索模块的Delegate，此处记得不用的时候需要置nil，否则影响内存的释放
@property (nonatomic, retain) id<BMKGeocodeSearchDelegate> delegate;

/**
 *根据地址名称获取地理信息
 *异步函数，返回结果在BMKGeocodeSearchDelegate的onGetAddrResult通知
 *@param geocodeOption       geo检索信息类
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)geocode:(BMKGeocodeSearchOption*)geocodeOption;
/**
 *根据地理坐标获取地址信息
 *异步函数，返回结果在BMKGeocodeSearchDelegate的onGetAddrResult通知
 *@param reverseGeocodeOption 反geo检索信息类
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)reverseGeocode:(BMKReverseGeocodeOption*)reverseGeocodeOption;


@end

///搜索delegate，用于获取搜索结果
@protocol BMKGeocodeSearchDelegate<NSObject>
@optional
/**
 *返回地址信息搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结BMKGeocodeSearch果
 *@param error 错误号，@see BMKSearchErrorCode
 */
- (void)onGetGeocodeResult:(BMKGeocodeSearch *)searcher result:(BMKGeoCodeResult *)result errorCode:(BMKSearchErrorCode)error;

/**
 *返回反地理编码搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号，@see BMKSearchErrorCode
 */
- (void)onGetReverseGeocodeResult:(BMKGeocodeSearch *)searcher result:(BMKReverseGeoCodeResult *)result errorCode:(BMKSearchErrorCode)error;

@end




