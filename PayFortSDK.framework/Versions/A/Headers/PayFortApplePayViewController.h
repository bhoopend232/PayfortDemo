//
//  PayFortApplePayViewController.h
//  PayFortSDK
//
//  Created by AlKalouti on 7/30/17.
//  Copyright © 2017 PayFort. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PayFortApplePayViewController : UIViewController

+ (BOOL)canMakeApplePayment;

- (void)callApplePay:(UIViewController *)viewController paymentSummaryItems:(NSArray *)arr countryCode:(NSString * )countryCode currencyCode:(NSString *)currencyCode merchantIdentifier:(NSString *)merchantIdentifier;

@end
