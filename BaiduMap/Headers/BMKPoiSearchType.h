/*
 *  BMKPoiSearchType.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
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

///城市列表信息类
@interface BMKCityListInfo : NSObject
{
	NSString* _city;
	int		  _num;
}
///城市名称
@property (nonatomic, retain) NSString* city;
///该城市所含搜索结果数目
@property (nonatomic) int num;

@end


///POI信息类
@interface BMKPoiInfo : NSObject
{
	NSString* _name;			///<POI名称
    NSString* _uid;
	NSString* _address;		///<POI地址
	NSString* _city;			///<POI所在城市
	NSString* _phone;		///<POI电话号码
	NSString* _postcode;		///<POI邮编
	int		  _epoitype;		///<POI类型，0:普通点 1:公交站 2:公交线路 3:地铁站 4:地铁线路
	CLLocationCoordinate2D _pt;	///<POI坐标
}
///POI名称
@property (nonatomic, retain) NSString* name;
///POIuid
@property (nonatomic, retain) NSString* uid;
///POI地址
@property (nonatomic, retain) NSString* address;
///POI所在城市
@property (nonatomic, retain) NSString* city;
///POI电话号码
@property (nonatomic, retain) NSString* phone;
///POI邮编
@property (nonatomic, retain) NSString* postcode;
///POI类型，0:普通点 1:公交站 2:公交线路 3:地铁站 4:地铁线路
@property (nonatomic) int epoitype;
///POI坐标
@property (nonatomic) CLLocationCoordinate2D pt;
@end



///POI搜索结果类
@interface BMKPoiResult : NSObject
{
	int _totalPoiNum;		///<本次POI搜索的总结果数
	int _currPoiNum;			///<当前页的POI结果数
	int _pageNum;			///<本次POI搜索的总页数
	int _pageIndex;			///<当前页的索引
	
	NSArray* _poiInfoList;	///<POI列表，成员是BMKPoiInfo
	NSArray* _cityList;		///<城市列表，成员是BMKCityListInfo
}
///本次POI搜索的总结果数
@property (nonatomic) int totalPoiNum;
///当前页的POI结果数
@property (nonatomic) int currPoiNum;
///本次POI搜索的总页数
@property (nonatomic) int pageNum;
///当前页的索引
@property (nonatomic) int pageIndex;
///POI列表，成员是BMKPoiInfo
@property (nonatomic, retain) NSArray* poiInfoList;
///城市列表，成员是BMKCityListInfo
@property (nonatomic, retain) NSArray* cityList;		

@end



