//
//  BMKVersion.h
//  BMapKit
//
//  Copyright 2011 Baidu Inc. All rights reserved.
//

#import <UIKit/UIKit.h>


/*****更新日志：*****
 V0.1.0： 测试版
 支持地图浏览，基础操作
 支持POI搜索
 支持路线搜索
 支持地理编码功能
 --------------------
 V1.0.0：正式发布版
 地图浏览，操作，多点触摸，动画
 标注，覆盖物
 POI、路线搜索
 地理编码、反地理编码
 定位图层
 --------------------
 V1.1.0：
 离线地图支持
 --------------------
 V1.1.1：
 增加suggestionSearch接口
 可以动态更改annotation title
 fix小内存泄露问题
 --------------------
 V1.2.1：
 增加busLineSearch接口
 修复定位圈范围内不能拖动地图的bug
 
 --------------------
 V2.0.0
 
 新增：
 全新的3D矢量地图渲染
 BMKMapView设定地图旋转俯视角度：rotation、overlooking
 BMKMapView设定指南针显示位置：compassPosition
 BMKMapView控制生命周期：viewWillAppear、viewWillDisappear
 地图标注可点，BMKMapViewDelegate新增接口回调接口onClickedMapPoi
 BMKAnnotationView设置annotation是否启用3D模式：enabled3D
 overlay绘制方式改变，采用opengl绘制：
 BMKOverlayView使用opengl渲染接口：glRender子类重载此函数实现gl绘制
 基本opengl线绘制：renderLinesWithPoints
 基本opengl面绘制：renderRegionWithPointsl
 全新的矢量离线地图数据：
 BMKOfflineMap下载离线地图：start
 BMKOfflineMap更新离线地图：update
 BMKOfflineMap暂停下载或更新：pasue
 获得热点城市列表：getHotCityList
 获得支持离线数据的城市：getOfflineCityList
 根据城市名查询城市信息：searchCity
 更新：
 BMKMapView的缩放级别zoomLevel更新为float型，实现无级缩放
 更新地图类型枚举：
 enum {   BMKMapTypeStandard  = 1,              ///< 标准地图
 BMKMapTypeTrafficOn = 2,              ///< 实时路况
 BMKMapTypeSatellite = 4,              ///< 卫星地图
 BMKMapTypeTrafficAndSatellite = 8,    ///< 同时打开实时路况和卫星地图
 };
 
 
 --------------------
 v2.0.1
 新增：
 §	MapView增加事件监听
 BMKMapviewDelegate中- mapView: onClickedMapBlank:方法监听地图单击事件
 BMKMapviewDelegate中- mapView: onDoubleClick:方法监听地图双击事件
 BMKMapviewDelegate中- mapView: onLongClick:方法监听地图长按事件
 §	地图截图功能
 BMKmapview中 -(UIImage*) takeSnapshot;
 §	路径规划增加途经点
 BMKSearch中- (BOOL)drivingSearch: startNode: endCity: endNode: throughWayPoints:
 §	suggestion搜索支持按城市搜索
 优化：
 §	全面支持iPad
 §	优化添加海量annotation逻辑
 §	BMKOfflineMap中：
 - (BOOL)pasue:(int)cityID;
 改为
 - (BOOL)pause:(int)cityID
 §	BMKMapview中：
 @property (nonatomic) CGPoint compassPositon;
 改为
 @property (nonatomic) CGPoint compassPosition;
 §	BMKRouteAddrResult结构添加属性：
 @synthesize wayPointPoiList;
 @synthesize wayPointCityList;
 §	BMKPlanNode中添加属性：
 @synthesize cityName; 添加城市属性
 §	BMKSuggestionresult结构添加属性：
 @synthesize districtList; 返回区域列表
 修复：
 §	修复与第三方类库冲突的问题
 修复与gzip、Reachability、png、jpeg、json、xml、sqlite等第三方类库冲突问题
 
 
 --------------------
 v2.0.2
 新增：
 1.全新的key验证体系
 
 2.增加短串分享接口
 1）在BMKType中新增数据结构：BMK_SHARE_URL_TYPE（分享串数据类型）
 2）在BMKSearch中新增接口-(BOOL)poiDetailShareUrl:(NSString*) uid; 发起poi短串搜索
 3）在BMKSearch中新增接口-(BOOL)reverseGeoShareUrl:(CLLocationCoordinate2D)coor
                              poiName:(NSString*)name
                              poiAddress:(NSString*)address; 发起反geo短串搜索
 4）在BMKSearchDelegate中新增接口-(void)onGetShareUrl:(NSString*) url
                                      withType:(BMK_SHARE_URL_TYPE) urlType
                                      errorCode:(int)error; 返回短串分享url
 3.比例尺控件
 1）在BMKMapview中新增属性@property (nonatomic) BOOL showMapScaleBar;比例尺是否显示
 2）在BMKMapview中新增属性@property (nonatomic) CGPoint mapScaleBarPosition;比例尺显示位置
 
 4.定位罗盘效果
 1）在BMKMapview中新增数据结构：BMKUserTrackingMode（定位模式）
 2）在BMKMapview中新增属性@property (nonattomic) BMKUserTrackingMode userTrackingMode; 设定定位模式
 
 5.驾车避让拥堵策略
 1）在BMKSearch中新增驾车检索策略常量BMKCarTrafficFIRST = 60,///<驾车检索策略常量：躲避拥堵
 
 6.路径查询增加时间、打车费用结果
 1）在BMKSearch中新增类：BMKTime（此类代表一个时间段，每个属性都是一个时间段。）
 2）在BMKTransitRoutePlan中新增属性@property (nonatomic) float price; 白天打车估价，单位(元)
 3）在BMKTransitRoutePlan中新增属性@property (nonatomic, retain) BMKTime* time; 方案所用时间
 4）在BMKRoutePlan中新增属性@property (nonatomic, retain) BMKTime* time; 方案预计的行驶时间
  
 优化：
 1）对在BMKMapview中的接口- (void)removeAnnotations:(NSArray *)annotations;（移除一组标注）进行了优化
 
 修复：
 1）修复离线地图——支持离线包的城市列表中省份下无子城市的问题
 2）修复前台数据请求后退至后台opengl继续渲染，应用Crash的问题
 *********************/


/**
 *获取当前地图API的版本号
 *return  返回当前API的版本号
 */
UIKIT_STATIC_INLINE NSString* BMKGetMapApiVersion()
{
	return @"2.0.2";
}
