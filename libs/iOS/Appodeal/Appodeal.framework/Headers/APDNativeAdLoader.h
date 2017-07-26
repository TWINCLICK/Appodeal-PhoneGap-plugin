//
//  APDNativeAdLoader.h
//  Appodeal
//
//  AppodealSDK version 2.1.0-ReleaseCandidate-5
//
//  Copyright © 2017 Appodeal, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Appodeal/APDNativeAd.h>
#import <Appodeal/APDSdk.h>
#import <Appodeal/APDDefines.h>


@class APDNativeAdLoader;

@protocol APDNativeAdRequestDelegate <NSObject>

@optional

- (void)nativeAdLoaderDidStartMediation:(APDNativeAdLoader *)nativeAdLoader;
- (void)nativeAdLoader:(APDNativeAdLoader *)nativeAdLoader willSendRequestToAdNetwork:(NSString *)adNetwork;
- (void)nativeAdLoader:(APDNativeAdLoader *)nativeAdLoader didRecieveResponseFromAdNetwork:(NSString *)adNetwork wasFilled:(BOOL)filled;
- (void)nativeAdLoader:(APDNativeAdLoader *)nativeAdLoader didFinishMediationAdWasFilled:(BOOL)filled;

@end

/*!
 *  Declaration of native ad loader delegate
 */
@protocol APDNativeAdLoaderDelegate <NSObject>

/*!
 *  Method called when loader recieve native ad.
 *  Count of array can be little than requested capacity
 *
 *  @discussion This API will be available in future release
 *
 *  @param loader    Ready loader
 *  @param nativeAds Array of native ads of requested type
 */
- (void)nativeAdLoader:(APDNativeAdLoader *)loader didLoadNativeAds:(NSArray <__kindof APDNativeAd *> *)nativeAds;

/*!
 *  Method called when loaded recieve native ad.
 *
 *  @param loader   Ready loader
 *  @param nativeAd Native ad to show
 */
- (void)nativeAdLoader:(APDNativeAdLoader *)loader didLoadNativeAd:(APDNativeAd *)nativeAd NS_UNAVAILABLE;

/*!
 *  Method called if loader mediation failed
 *
 *  @param loader Failed loader
 *  @param error  Occured error
 */
- (void)nativeAdLoader:(APDNativeAdLoader *)loader didFailToLoadWithError:(NSError *)error;

@end

/*!
 *  You can call -loadAdWithType: or -loadAdWithType:capacity: several times on one loader
 */
@interface APDNativeAdLoader : NSObject


@property (weak, nonatomic) id<APDNativeAdRequestDelegate> requestDelegate;

/*!
 *  Set loader delegate
 */
@property (weak, nonatomic) id<APDNativeAdLoaderDelegate> delegate;

/*!
 *  Set custom placement tuned on Appodeal Dashboard
 */
@property (copy, nonatomic) NSString *placement;

/*!
 *  Set custom sdk
 */
@property (weak, nonatomic) APDSdk *customSdk;

/*!
 *  Call this method to load native ad.
 *  Capacity equals to 1, it's means that array of native ads
 *  returned in -nativeAdLoader: didLoadNativeAds: will contain
 *  only one instance of native ad
 *
 *  @param type Native ad type
 */
- (void)loadAdWithType:(APDNativeAdType)type;

/*!
 *  Call this method to load native ad.
 *  Capacity equals to 1, it's means that array of native ads
 *  returned in -nativeAdLoader: didLoadNativeAds: will contain
 *  only one instance of native ad
 *
 *
 *
 *  @param type     Native ad type
 *  @param capacity Interger value from 1 to 11
 */
- (void)loadAdWithType:(APDNativeAdType)type capacity:(NSInteger)capacity;


@end
