Baidu-Map-SDK-iOS
=================

An git mirror of Baidu Map SDK library for iOS from http://developer.baidu.com/map/sdk-ios.htm

The integration guideline lies on [http://developer.baidu.com/map/sdk-ios.htm](http://developer.baidu.com/map/sdk-ios.htm).

百度地图 iOS SDK是一套基于iOS4.3及以上(iOS SDKv1.2.3及以前版本支持iOS3.0及以上)版本设备的应用程序接口，不仅提供展示地图的基本接口，还提供本地搜索、路线规划、定位等服务。

您可以使用百度地图iOS SDK开发适用于移动设备的地图应用，通过接口，您可以轻松访问百度服务和数据，构建功能丰富、交互性强的地图应用程序。百度iOS SDK目前支持iPhone/iPad4.3以上的版本（iOS SDKv1.2.3支持iphone3.0以上的版本）。

该套SDK提供的服务是免费的，任何非营利性程序均可使用，您需要先[申请密钥](http://developer.baidu.com/map/ios-mobile-apply-key.htm)（key），才可使用该套SDK接口。任何非营利性产品请直接使用，商业目的产品使用前请参考[使用须知](http://developer.baidu.com/map/sdk-ios.htm#)。

注意：为了给用户提供更优质的服务，iOS SDK自v2.0.2版本开始采用了全新的Key验证体系。因此，当您选择使用v2.0.2及之后版本的SDK时，需要到新的Key申请页面进行全新Key的申请，申请及配置流程请参考[开发指南对应章节](http://developer.baidu.com/map/sdkiosdev-1.htm#.E7.AE.80.E4.BB.8B3)。（选择使用v2.0.1及之前版本SDK的开发者，[申请密钥（Key）](http://developer.baidu.com/map/ios-mobile-apply-key.htm)的方式不变）。

在您使用百度地图iOS SDK之前，请先阅读[百度地图API使用条款](http://developer.baidu.com/map/law.htm)。

### 功能介绍
* 地图展示：包括2D图、卫星图、3D图地图展示。

* 地图操作：提供平移、缩放、双指手势操作、底图旋转等地图相关操作及对地图点击、双击、长按事件的监听。

* 短串分享：将POI点、反Geo点，生成短链接串，此链接可通过短信等形式分享给好友，好友在终端设备点击此链接可快速打开Web地图、百度地图客户端进行信息展示。

* 自定义绘制：提供自定义绘折线、多边形、圆的功能。

* 地图搜索：提供根据关键字进行范围检索、城市检索和周边检索。

* 线路规划：提供公交、驾车（支持添加途经点） 和步行三种类型，多种方案（不含地铁、时间优先、最少换乘、最少步行、驾车避让拥堵）的线路规划。

* 地理编码：提供地址信息与坐标之间的相互转换。

* 位置标注：提供一个或多个POI位置标注，且支持用户自定义图标。

* 实时路况：支持城际（城市之间，如高速）和全国[多个城市](http://developer.baidu.com/map/question.htm#qa0033)的实时路况。

* 离线地图：提供离线地图下载的功能，可节省用户流量。

* 定位：与iOS系统定位完美结合，便捷展示当前位置信息。