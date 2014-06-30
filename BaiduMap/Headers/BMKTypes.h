//
//  BMKType.h
//  MapPlatform
//
//  Created by BaiduMapAPI on 13-3-26.
//  Copyright (c) 2013年 baidu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>

#import <UIKit/UIKit.h>
typedef enum
{
    BMK_COORDTYPE_GPS = 0, ///GPS设备采集的原始GPS坐标
    BMK_COORDTYPE_COMMON,  ///google地图、soso地图、aliyun地图、mapabc地图和amap地图所用坐标
} BMK_COORD_TYPE;
enum {
    BMKMapTypeStandard   = 1,               ///< 标准地图
    BMKMapTypeTrafficOn  = 2,               ///< 实时路况 
    BMKMapTypeSatellite  = 4,               ///< 卫星地图
    BMKMapTypeTrafficAndSatellite  = 8,     ///< 同时打开实时路况和卫星地图
};
typedef NSUInteger BMKMapType;


typedef enum {
	BMKErrorOk = 0,	///< 正确，无错误
    BMKErrorConnect = 2,	///< 网络连接错误
	BMKErrorData = 3,	///< 数据错误
	BMKErrorRouteAddr = 4, ///<起点或终点选择(有歧义)
	BMKErrorResultNotFound = 100,	///< 搜索结果未找到
	BMKErrorLocationFailed = 200,	///< 定位失败
	BMKErrorPermissionCheckFailure = 300,	///< 百度地图API授权Key验证失败
	BMKErrorParse = 310		///< 数据解析失败
}BMKErrorCode;
//key验证结果状态码
typedef enum {
    E_PERMISSIONCHECK_OK = 0,	// 授权验证通过
	E_PERMISSIONCHECK_KEY_ERROR = -1,	// Key格式错误，无效Key
	E_PERMISSIONCHECK_PV_LIMITED = -2,	//该应用已到达最大日访问量
	E_PERMISSIONCHECK_KEY_LOCKED = -3,	//该Key被封禁
	E_PERMISSIONCHECK_SHOULD_PAY = -4,	//需要续费使用
	E_PERMISSIONCHECK_NONE = 1,	// 尚未进行验证
	E_PERMISSIONCHECK_CHECHING = 2,	// 正在验证⋯⋯
	E_PERMISSIONCHECK_SERVER_ERROR = 3,	// 服务端错误
	E_PERMISSIONCHECK_NETWORK_ERROR = 4,	// 服务端错日误
}BMKPermissionCheckResultCode;
//检索结果状态码
typedef enum{
    BMK_SEARCH_NO_ERROR =0,///<检索结果正常返回
    BMK_SEARCH_AMBIGUOUS_KEYWORD,///<检索词有岐义
    BMK_SEARCH_AMBIGUOUS_ROURE_ADDR,///<检索地址有岐义
    BMK_SEARCH_NOT_SUPPORT_BUS,///<该城市不支持公交搜索
    BMK_SEARCH_NOT_SUPPORT_BUS_2CITY,///<不支持跨城市公交
    BMK_SEARCH_RESULT_NOT_FOUND,///<没有找到检索结果
    BMK_SEARCH_ST_EN_TOO_NEAR,///<起终点太近
}BMKSearchErrorCode;

///表示一个经纬度范围
typedef struct {
    CLLocationDegrees latitudeDelta;	///< 纬度范围
    CLLocationDegrees longitudeDelta;	///< 经度范围
} BMKCoordinateSpan;

///表示一个经纬度区域
typedef struct {
    CLLocationCoordinate2D northEast;	///< 东北角点经纬度坐标
    CLLocationCoordinate2D southWest;	///< 西南角点经纬度坐标
} BMKCoordinateBounds;

///表示一个经纬度区域
typedef struct {
	CLLocationCoordinate2D center;	///< 中心点经纬度坐标
	BMKCoordinateSpan span;		///< 经纬度范围
} BMKCoordinateRegion;

///表示一个经纬度坐标点
typedef struct {
	int latitudeE6;		///< 纬度，乘以1e6之后的值
	int longitudeE6;	///< 经度，乘以1e6之后的值
} BMKGeoPoint;

///地理坐标点，用直角地理坐标表示
typedef struct {
    double x;	///< 横坐标
    double y;	///< 纵坐标
} BMKMapPoint;

///矩形大小，用直角地理坐标表示
typedef struct {
    double width;	///< 宽度
    double height;	///< 高度
} BMKMapSize;

///矩形，用直角地理坐标表示
typedef struct {
    BMKMapPoint origin; ///< 屏幕左上点对应的直角地理坐标
    BMKMapSize size;	///< 坐标范围
} BMKMapRect;

///地图缩放比例
typedef CGFloat BMKZoomScale;

/// 经过投影后的世界范围大小，与经纬度（-85，180）投影后的坐标值对应
UIKIT_EXTERN const BMKMapSize BMKMapSizeWorld;
/// 经过投影后的世界矩形范围
UIKIT_EXTERN const BMKMapRect BMKMapRectWorld;
/// 空的直角坐标矩形
UIKIT_EXTERN const BMKMapRect BMKMapRectNull;

///线路检索节点信息,一个路线检索节点可以通过经纬度坐标或城市名加地名确定
@interface BMKPlanNode : NSObject{
    NSString*              _cityName;
    NSString*              _name;
    CLLocationCoordinate2D _pt;
}

///节点所在城市
@property (nonatomic, retain) NSString* cityName;
///节点名称
@property (nonatomic, retain) NSString* name;
///节点坐标
@property (nonatomic) CLLocationCoordinate2D pt;
@end


