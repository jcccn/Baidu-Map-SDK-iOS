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
//key验证结果状态码
enum BMKPermissionCheckResultCode {
    E_PERMISSIONCHECK_OK = 0,	// 授权验证通过
	E_PERMISSIONCHECK_KEY_ERROR = -1,	// Key格式错误，无效Key
	E_PERMISSIONCHECK_PV_LIMITED = -2,	//该应用已到达最大日访问量
	E_PERMISSIONCHECK_KEY_LOCKED = -3,	//该Key被封禁
	E_PERMISSIONCHECK_SHOULD_PAY = -4,	//需要续费使用
	E_PERMISSIONCHECK_NONE = 1,	// 尚未进行验证
	E_PERMISSIONCHECK_CHECHING = 2,	// 正在验证⋯⋯
	E_PERMISSIONCHECK_SERVER_ERROR = 3,	// 服务端错误
	E_PERMISSIONCHECK_NETWORK_ERROR = 4,	// 服务端错日误
};

typedef enum
{
    BMKPOI_DETAIL_SHARE_URL = 0, ///POI详情url
    BMKRGC_SHARE_URL,            ///反地理坐标url
} BMK_SHARE_URL_TYPE;
