//
//  PayFortApplePayHandler.h
//  PayFortSDK
//
//  Created by AlKalouti on 7/31/17.
//  Copyright © 2017 PayFort. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <PassKit/PassKit.h>

@interface PayFortApplePayHandler : NSObject//<PAYFORTSDKCertificateDelegate,PAYFORTSDKConnectionManagerDelegate>

typedef void (^PAYFORTTransactionSuccess)(NSDictionary * requestDic, NSDictionary * responeDic);
typedef void (^PAYFORTTransactionFaild)(NSDictionary * requestDic, NSDictionary * responeDic, NSString * message);

@property (nonatomic, assign) BOOL IsShowResponsePage;


- (void)callPayFortWithRequest:(NSMutableDictionary *)RequestFort
           applePayPayment:(PKPayment *)payment
         currentViewController:(UIViewController *)controller
                       Success:(PAYFORTTransactionSuccess)success
                         Faild:(PAYFORTTransactionFaild)faild;


@end
