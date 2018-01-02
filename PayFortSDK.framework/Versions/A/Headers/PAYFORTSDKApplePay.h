//
//  PAYFORTSDKApplePay.h
//  PayFortSDK
//
//  Created by AlKalouti on 7/29/17.
//  Copyright © 2017 PayFort. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PassKit/PassKit.h>

@interface PAYFORTSDKApplePay : PKPaymentAuthorizationViewController <PKPaymentAuthorizationViewControllerDelegate>

+ (BOOL)canMakeApplePayment;

- (void)callApplePay:(UIViewController *)viewController paymentSummaryItems:(NSArray *)arr countryCode:(NSString * )countryCode currencyCode:(NSString *)currencyCode merchantIdentifier:(NSString *)merchantIdentifier;

@end
