/*
 *  BMKCloudPOIList.h
 *  BMapKit
 *
 *  Copyright 2013 Baidu Inc. All rights reserved.
 *
 */
#import <Foundation/Foundation.h>
/// 云检索结果列表类
@interface BMKCloudPOIList : NSObject {
    NSInteger               _status;
    NSInteger               _total;
    NSInteger               _size;
    NSInteger               _pageNum;
    NSArray                 *_POIs;
    
}
///搜索状态
@property (nonatomic, assign) NSInteger     status;
///结果总数
@property (nonatomic, assign) NSInteger     total;
///当前页返回数量
@property (nonatomic, assign) NSInteger     size;
///页数
@property (nonatomic, assign) NSInteger     pageNum;
///POI结果列表
@property (nonatomic, retain) NSArray       *POIs;

@end


/// 云检索结果信息类
@interface BMKCloudPOIInfo : NSObject {
    int             _uid;
    int             _geotableId;
    NSString        *_title;
    NSString        *_address;
    NSString        *_province;
    NSString        *_city;
    NSString        *_district;
    float           _latitude;
    float           _longitude;
    NSString        *_tags;
    float           _distance;
    float           _weight;
    NSMutableDictionary *_customDict;
    int             _creattime;
    int             _modifytime;
    int             _type;
    

}
///poi数据id
@property (nonatomic, assign) int             uid;
///所属table的id
@property (nonatomic, assign) int             geotableId;
///poi名称
@property (nonatomic, retain) NSString        *title;
///poi地址
@property (nonatomic, retain) NSString        *address;
///poi所属省
@property (nonatomic, retain) NSString        *province;
///poi所属城市
@property (nonatomic, retain) NSString        *city;
///poi所属区县
@property (nonatomic, retain) NSString        *district;
///poi所处位置的纬度
@property (nonatomic, assign) float           latitude;
///poi所处位置的经度
@property (nonatomic, assign) float           longitude;
///poi标签
@property (nonatomic, retain) NSString        *tags;
///poi距离
@property (nonatomic, assign) float           distance;
///权重
@property (nonatomic, assign) float           weight;
///自定义列
@property (nonatomic, retain) NSMutableDictionary *customDict;
///创建时间
@property (nonatomic, assign) int             creattime;
///修改时间
@property (nonatomic, assign) int             modifytime;
///类型
@property (nonatomic, assign) int             type;

@end

