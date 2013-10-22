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
 
 --------------------
 v2.1.0
 新增：
 1.全面接入LBS.云V2.0，全面开放LBS.云检索能力
 1)在BMKCloudSearchInfo中新增类BMKBaseCloudSearchInfo，BMKCloudSearchInfo，BMKCloudLocalSearchInfo，BMKCloudNearbySearchInfo，BMKCloudBoundSearchInfo，BMKCloudDetailSearchInfo来存储云检索参数
 2)在BMKCloudPOIList中新增类BMKCloudPOIList来存储云检索结果
 3)在BMKCloudSearch中新增数据结构：BMKCloudSearchType（云检索类型）
 4)在BMKCloudSearch中新增接口- (BOOL)localSearchWithSearchInfo:;发起本地云检索
 5)在BMKCloudSearch中新增接口- (BOOL) nearbySearchWithSearchInfo:;发起周边云检索
 6)在BMKCloudSearch中新增接口- (BOOL) boundSearchWithSearchInfo:;发起矩形云检索
 7)在BMKCloudSearch中新增接口- (BOOL) detailSearchWithSearchInfo:;发起详情云检索
 8)在BMKCloudSearch中新增接口- (void)onGetCloudPoiResult: searchType: errorCode:;返回云检索列表结果
 9)在BMKCloudSearch中新增接口- (void) onGetCloudPoiDetailResult: searchType: errorCode:;返回云检索详情结果
 2.增加图片图层BMKGroundOverlay、BMKGroundOverlayView
 1)在BMKGroundOverlay中新增属性@property (nonatomic,assign) CLLocationCoordinate2D pt;两种绘制GroundOverlay的方式之一：绘制的位置地理坐标，与anchor配对使用
 2)在BMKGroundOverlay中新增属性@property (nonatomic,assign) CGPoint anchor;用位置绘制时图片的锚点，图片左上角为(0.0f,0.0f),向右向下为正
 3)在BMKGroundOverlay中新增属性@property (nonatomic,assign) BMKCoordinateBounds bound;两种绘制GroundOverlay的方式之二：绘制的地理区域范围，图片在此区域内合理缩放
 4)在BMKGroundOverlay中新增属性@property(nonatomic, strong) UIImage *icon;绘制图片
 5)在BMKGroundOverlay中新增接口+(BMKGroundOverlay*)groundOverlayWithPosition:zoomLevel:anchor:icon:;根据指定经纬度坐标生成一个groundOverlay
 6)在BMKGroundOverlay中新增接口+(BMKGroundOverlay*) groundOverlayWithBounds:icon:;根据指定区域生成一个groundOverlay
 3.增加自定义泡泡
 1)在BMKActionPaopaoView中新增接口- (id)initWithCustomView:(UIView*)customView;泡泡显示View自定义
 4.增加地图中心点映射屏幕点
 1)在BMKMapView中新增接口- (void)setMapCenterToScreenPt:;设置地图中心点在地图中的屏幕坐标位置
 5.增加以手势触摸点中心为基准旋转缩放底图功能和控制开关
 1)在BMKMapView中新增属性@property(nonatomic, getter=isChangeWithTouchPointCenterEnabled) BOOL ChangeWithTouchPointCenterEnabled;设定地图View能否支持以手势中心点为轴进行旋转和缩放（默认以屏幕中心点为旋转和缩放中心）
 6.增加同时改变地图俯角，旋转角度，缩放比例，中心点接口
 1)新增类BMKMapStatus来表示地图状态参数
 2)在BMKMapView中新增接口- (void)setMapStatus:;设置地图状态
 3)在BMKMapView中新增接口- (void)setMapStatus: withAnimation:;设置地图状态（指定是否需要动画效果）
 4)在BMKMapView中新增接口- (void)setMapStatus: withAnimation: withAnimationTime:;设置地图状态（指定是否需要动画效果＋指定动画时间）
 5)在BMKMapView中新增接口- (BMKMapStatus*)getMapStatus;获取地图状态
 7.增加地图状态改变实时通知
 1)在BMKMapView中新增接口- (void)mapStatusDidChanged:;地图状态改变完成后会调用此接口
 
 优化：
 1.点击Annotation置顶
 1)在BMKMapView中新增属性@property (nonatomic, assign) BOOL isSelectedAnnotationViewFront;设定是否总让选中的annotaion置于最前面
 2.定位脱离MapView
 1)在BMKUserLocation中新增接口-(void)startUserLocationService;打开定位服务
 2)在BMKUserLocation中新增接口-(void)stopUserLocationService;关闭定位服务
 3)在BMKUserLocation中新增接口- (void)viewDidGetLocatingUser:;开启定位后，会自动调用此接口返回当前位置的经纬度
 3.定位图层样式自定义灵活性优化
 1)新增类BMKLocationViewDisplayParam来存储定位图层自定义参数
 2)在BMKMapView中新增接口- (void)updateLocationViewWithParam:;动态定制定位图层样式
 
 修复：
 1)修复点击annotation回调长按监听接口- (void)mapview: onLongClick:的问题
 2)修复TransitRoutePlan中Content属性为空的问题
 3)修复缩放底图，接口- (void)mapView: regionDidChangeAnimated:不回调的问题
 4)修复从其他页面返回原页面泡泡被压盖的问题
 5)解决WiFi无网络信号时首次加载卡屏的问题
 *********************/


/**
 *获取当前地图API的版本号
 *return  返回当前API的版本号
 */
UIKIT_STATIC_INLINE NSString* BMKGetMapApiVersion()
{
	return @"2.1.0";
}
