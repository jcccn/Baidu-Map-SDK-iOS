/*
 *  BMKSearch.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "BMKGeometry.h"
#import "BMKPoiSearchType.h"
#import "BMKRouteSearchType.h"
#import "BMKGeocodeType.h"
#import "BMKTypes.h"

@protocol BMKSearchDelegate;

enum {
	BMKInvalidCoordinate = -1,  ///<无效坐标
    BMKCarTrafficFIRST = 60,    ///<驾乘检索策略常量：躲避拥堵，若无实时路况，默认按照时间优先策略
	BMKCarTimeFirst = 0,		///<驾乘检索策略常量：时间优先
	BMKCarDisFirst,				///<驾乘检索策略常量：最短距离
	BMKCarFeeFirst,				///<驾乘检索策略常量：较少费用
	BMKBusTimeFirst,			///<公交检索策略常量：时间优先
	BMKBusTransferFirst,		///<公交检索策略常量：最少换乘
	BMKBusWalkFirst,			///<公交检索策略常量：最小步行距离
	BMKBusNoSubway,				///<公交检索策略常量：不含地铁
	BMKTypeCityList = 7,		///<POI检索类型：城市列表
	BMKTypePoiList = 11,		///<POI检索类型：城市内搜索POI列表
	BMKTypeAreaPoiList = 21,	///<POI检索类型：范围搜索、周边搜索POI列表
	BMKTypeAreaMultiPoiList = 45	///<POI检索类型：多关键字范围搜索、周边搜索POI列表
};
///搜索服务
@interface BMKSearch : NSObject 
/// 检索模块的Delegate，此处记得不用的时候需要置nil，否则影响内存的释放
@property (nonatomic, retain) id<BMKSearchDelegate> delegate;
///公交检索策略
@property (nonatomic) int transitPolicy;
///驾乘检索策略
@property (nonatomic) int drivingPolicy;

/**
 *城市POI检索
 *异步函数，返回结果在BMKSearchDelegate的onGetPoiResult通知
 *@param city 城市名，如果为nil则在当前底图范围搜索
 *@param key 关键词
 *@param index 页码，如果是第一次发起搜索，填0，根据返回的结果可以去获取第n页的结果，页码从0开始
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)poiSearchInCity:(NSString*)city withKey:(NSString*)key pageIndex:(int)index;

/**
 *根据范围和检索词发起范围检索
 *异步函数，返回结果在BMKSearchDelegate的onGetPoiResult通知
 *@param key 关键词
 *@param ptLB 地理坐标，范围的左下角
 *@param ptRT 地理坐标，范围的右下角
 *@param index 页码，如果是第一次发起搜索，填0，根据返回的结果可以去获取第n页的结果，页码从0开始
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)poiSearchInbounds:(NSString*)key leftBottom:(CLLocationCoordinate2D)ptLB rightTop:(CLLocationCoordinate2D)ptRT pageIndex:(int)index;

/**
 *根据范围和检索词发起范围检索
 *异步函数，返回结果在BMKSearchDelegate的onGetPoiResult通知
 *@param keys 关键词列表，必须大于1个，小于等于10个
 *@param ptLB 地理坐标，范围的左下角
 *@param ptRT 地理坐标，范围的右下角
 *@param index 页码，如果是第一次发起搜索，填0，根据返回的结果可以去获取第n页的结果，页码从0开始
 *@return 成功返回YES，否则返回NO
 */
//- (BOOL)poiMultiSearchInbounds:(NSArray*)keys leftBottom:(CLLocationCoordinate2D)ptLB rightTop:(CLLocationCoordinate2D)ptRT pageIndex:(int)index;

/**
 *根据中心点、半径和检索词发起周边检索
 *异步函数，返回结果在BMKSearchDelegate的onGetPoiResult通知
 *@param key 关键词
 *@param ptCenter 中心点地理坐标
 *@param radius 半径，单位：米 必须大于0
 *@param index 页码，如果是第一次发起搜索，填0，根据返回的结果可以去获取第n页的结果，页码从0开始
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)poiSearchNearBy:(NSString*)key center:(CLLocationCoordinate2D)ptCenter radius:(int)radius pageIndex:(int)index;

/**
 *根据中心点、半径和检索词发起周边检索
 *异步函数，返回结果在BMKSearchDelegate的onGetPoiResult通知
 *@param keys 关键词列表，必须大于1个，小于等于10个
 *@param ptCenter 中心点地理坐标
 *@param radius 半径，单位：米 必须大于0
 *@param index 页码，如果是第一次发起搜索，填0，根据返回的结果可以去获取第n页的结果，页码从0开始
 *@return 成功返回YES，否则返回NO
 */
//- (BOOL)poiMultiSearchNearBy:(NSArray*)keys center:(CLLocationCoordinate2D)ptCenter radius:(int)radius pageIndex:(int)index;


/**
 *获取poi详情短串分享url
 *异步函数，返回结果在BMKSearchDelegate的onGetShareUrl通知
 *@param uid poi的uid
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)poiDetailShareUrl:(NSString*) uid;

/**
 *获取反geo短串分享url
 *异步函数，返回结果在BMKSearchDelegate的onGetShareUrl通知
 *@param coor 经纬度坐标
 *@param name 标题
 *@param address 地址
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)reverseGeoShareUrl:(CLLocationCoordinate2D)coor
                     poiName:(NSString*)name
                  poiAddress:(NSString*)address;

/**
 *公交路线检索
 *异步函数，返回结果在BMKSearchDelegate的onGetTransitRouteResult通知
 *@param city 城市名，用于在哪个城市内进行检索
 *@param start 检索的起点，可通过关键字、坐标两种方式指定
 *@param end 检索的终点，可通过关键字、坐标两种方式指定
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)transitSearch:(NSString*)city startNode:(BMKPlanNode*)start endNode:(BMKPlanNode*)end;

/**
 *驾乘路线检索
 *异步函数，返回结果在BMKSearchDelegate的onGetDrivingRouteResult通知
 *@param startCity 起点所在城市，起点为坐标时可不填
 *@param start 检索的起点，可通过关键字、坐标两种方式指定
 *@param endCity 终点所在城市，终点为坐标时可不填
 *@param end 检索的终点，可通过关键字、坐标两种方式指定
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)drivingSearch:(NSString*)startCity startNode:(BMKPlanNode*)start endCity:(NSString*)endCity endNode:(BMKPlanNode*)end;

/**
 *驾乘路线检索
 *异步函数，返回结果在BMKSearchDelegate的onGetDrivingRouteResult通知
 *@param startCity 起点所在城市，起点为坐标时可不填
 *@param start 检索的起点，可通过关键字、坐标两种方式指定
 *@param endCity 终点所在城市，终点为坐标时可不填
 *@param end 检索的终点，可通过关键字、坐标两种方式指定
 *@param wayPointsArray 途经点数组，存储BMKPlanNode信息的节点。wayPointsArray为nil或空时，表示没有途经点。最多支持10个途经点，超过10个请求发送不成功。
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)drivingSearch:(NSString*)startCity startNode:(BMKPlanNode*)start endCity:(NSString*)endCity endNode:(BMKPlanNode*)end throughWayPoints:(NSArray*)wayPointsArray;


/**
 *步行路线检索
 *异步函数，返回结果在BMKSearchDelegate的onGetWalkingRouteResult通知
 *@param startCity 起点所在城市，起点为坐标时可不填
 *@param start 检索的起点，可通过关键字、坐标两种方式指定
 *@param endCity 终点所在城市，终点为坐标时可不填
 *@param end 检索的终点，可通过关键字、坐标两种方式指定
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)walkingSearch:(NSString*)startCity startNode:(BMKPlanNode*)start endCity:(NSString*)endCity endNode:(BMKPlanNode*)end;

/**
 *根据地理坐标获取地址信息
 *异步函数，返回结果在BMKSearchDelegate的onGetAddrResult通知
 *@param center 点坐标
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)reverseGeocode:(CLLocationCoordinate2D)center;

/**
 *根据地址名称获取地理信息
 *异步函数，返回结果在BMKSearchDelegate的onGetAddrResult通知
 *@param addr       地址信息
 *@param city       城市名称
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)geocode:(NSString*)addr withCity:(NSString*)city;

/**
 *搜索建议检索
 *@param key       搜索建议的检索关键字
 *异步函数，返回结果在BMKSearchDelegate的onGetSuggestionResult通知
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)suggestionSearch:(NSString*)key;

/**
 *特定城市内搜索建议检索
 *异步函数，返回结果在BMKSearchDelegate的onGetSuggestionResult通知
 *@param key      搜索建议的检索关键字
 *@param cityname 城市名，用于指定在特定城市内检索
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)suggestionSearch:(NSString*)key inCity:(NSString*)cityname;

/**
 *公交详情检索
 *异步函数，返回结果在BMKSearchDelegate的onGetBusDetailResult通知
 *@param city 城市名，用于在哪个城市内进行检索
 *@param busLineUid 公交线路的uid
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)busLineSearch:(NSString*)city withKey:(NSString*)busLineUid;

/**
 *设置每页容量
 *支持1-50.对下一次检索有效
 *@param capacity 指定的每页POI最大数目
 */
+ (void)setPageCapacity:(int)capacity;

/**
 *返回每页容量
 *@return 每页容量
 */
+ (int)getPageCapacity;
@end

///搜索delegate，用于获取搜索结果
@protocol BMKSearchDelegate<NSObject>
@optional
/**
 *返回POI搜索结果
 *@param searcher 搜索对象
 *@param poiResultList 搜索结果列表，成员类型为BMKPoiResult
 *@param type 返回结果类型： BMKTypePoiList,BMKTypeAreaPoiList,BMKAreaMultiPoiList
 *@param error 错误号，@see BMKErrorCode
 */
- (void)onGetPoiResult:(BMKSearch*)searcher result:(NSArray*)poiResultList searchType:(int)type errorCode:(int)error;
/**
 *返回公交搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号，@see BMKErrorCode
 */
- (void)onGetTransitRouteResult:(BMKSearch*)searcher result:(BMKPlanResult*)result errorCode:(int)error;
/**
 *返回驾乘搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号，@see BMKErrorCode
 */
- (void)onGetDrivingRouteResult:(BMKSearch*)searcher result:(BMKPlanResult*)result errorCode:(int)error;

/**
 *返回步行搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号，@see BMKErrorCode
 */
- (void)onGetWalkingRouteResult:(BMKSearch*)searcher result:(BMKPlanResult*)result errorCode:(int)error;

/**
 *返回地址信息搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号，@see BMKErrorCode
 */
- (void)onGetAddrResult:(BMKSearch*)searcher result:(BMKAddrInfo*)result errorCode:(int)error;

/**
 *返回suggestion搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号，@see BMKErrorCode
 */
- (void)onGetSuggestionResult:(BMKSearch*)searcher result:(BMKSuggestionResult*)result errorCode:(int)error;

/**
 *返回busdetail搜索结果
 *@param searcher 搜索对象
 *@param busLineResult 搜索结果
 *@param error 错误号，@see BMKErrorCode
 */
- (void)onGetBusDetailResult:(BMKSearch*)searcher result:(BMKBusLineResult*)busLineResult errorCode:(int)error;

/**
 *返回poi详情分享url
 *@param searcher 搜索对象
 *@param url 返回结果url
 *@param error 错误号，@see BMKErrorCode
 */
- (void)onGetShareUrl:(BMKSearch*)searcher result:(NSString*) url withType:(BMK_SHARE_URL_TYPE) urlType errorCode:(int)error;


@end




