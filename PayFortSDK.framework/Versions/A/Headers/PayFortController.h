//
//  testController.h
//  PayFortProject
//
//  Created by PayFort on 4/15/16.
//  Copyright © 2016 PayFort. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PassKit/PassKit.h>

@protocol PayFortDelegate
@required
- (void)sdkResult:(id)response __attribute__((deprecated("Replaced by callPayFortWithRequest:")));

@end

@interface PayFortController : UIViewController<UINavigationControllerDelegate>

typedef void (^PAYFORTTransactionSuccess)(NSDictionary * requestDic, NSDictionary * responeDic);
typedef void (^PAYFORTTransactionCanceled)(NSDictionary * requestDic, NSDictionary * responeDic);
typedef void (^PAYFORTTransactionFaild)(NSDictionary * requestDic, NSDictionary * responeDic, NSString * message);

typedef enum : NSUInteger {
    KPayFortEnviromentSandBox,
    KPayFortEnviromentProduction,
} KPayFortEnviroment;


@property (nonatomic, assign) BOOL IsShowResponsePage;

@property (nonatomic, assign) BOOL HideLoading;

@property (nonatomic, weak) id <PayFortDelegate> delegate __deprecated_msg("Please remove this line of code and use callPayFortWithRequest: with handler for better performance");

- (instancetype)initWithEnviroment:(KPayFortEnviroment)enviroment;

- (void)setPayFortCustomViewNib:(NSString *)customPayFortViewNib;

- (void)setPayFortRequest:(NSMutableDictionary*)RequestFort __deprecated_msg("Please remove this line of code and use callPayFortWithRequest: with handler for better performance");

- (void)callPayFort:(id)CurrentPreviousViewController __attribute__((deprecated("Replaced by callPayFortWithRequest:")));

- (NSString*)getUDID;


- (void)callPayFortWithRequest:(NSMutableDictionary *)RequestFort
         currentViewController:(UIViewController *)controller
                       Success:(PAYFORTTransactionSuccess)success
                      Canceled:(PAYFORTTransactionCanceled)canceled
                         Faild:(PAYFORTTransactionFaild)faild;


- (void)callPayFortForApplePayWithRequest:(NSMutableDictionary *)RequestFort
               applePayPayment:(PKPayment *)payment
         currentViewController:(UIViewController *)controller
                       Success:(PAYFORTTransactionSuccess)success
                         Faild:(PAYFORTTransactionFaild)faild;

@end
