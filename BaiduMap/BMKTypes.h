//
//  BMKType.h
//  MapPlatform
//
//  Created by BaiduMapAPI on 13-3-26.
//  Copyright (c) 2013年 baidu. All rights reserved.
//

#import <UIKit/UIKit.h>


enum {
    BMKMapTypeStandard   = 1,               ///< 标准地图    
    BMKMapTypeTrafficOn  = 2,               ///< 实时路况 
    BMKMapTypeSatellite  = 4,               ///< 卫星地图
    BMKMapTypeTrafficAndSatellite  = 8,     ///< 同时打开实时路况和卫星地图
};
typedef NSUInteger BMKMapType;


//UIKIT_EXTERN NSString *BMKErrorDomain;

enum BMKErrorCode {
	BMKErrorOk = 0,	///< 正确，无错误
    BMKErrorConnect = 2,	///< 网络连接错误
	BMKErrorData = 3,	///< 数据错误
	BMKErrorRouteAddr = 4, ///<起点或终点选择(有歧义)
	BMKErrorResultNotFound = 100,	///< 搜索结果未找到
	BMKErrorLocationFailed = 200,	///< 定位失败
	BMKErrorPermissionCheckFailure = 300,	///< 百度地图API授权Key验证失败
	BMKErrorParse = 310		///< 数据解析失败
};

typedef enum
{
    BMKPOI_DETAIL_SHARE_URL = 0, ///POI详情url
    BMKRGC_SHARE_URL,            ///反地理坐标url
} BMK_SHARE_URL_TYPE;
