//
//  PayFortView.h
//  PayFortProject
//
//  Created by PayFort on 4/15/16.
//  Copyright © 2016 PayFort. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JVFloatLabeledTextField/JVFloatLabeledTextField.h>

@class PFKJVFloatLabeledTextField;
@interface PayFortView : UIView<UITextFieldDelegate>

- (void)start;

- (void)setupLanguage:(NSString*)lang;

- (instancetype)initWitNibName:(NSString *)nibName inBundle:(NSBundle*)bundle;

@property (assign, nonatomic)  BOOL IsAutoCompleteMode;

@property (assign, nonatomic)  BOOL isPaymentOption;

@property (assign, nonatomic)  BOOL isHideRemberMe;

@property (assign, nonatomic)  BOOL isCustomNib;

@property (assign, nonatomic)  int CurrentTagTextField;

@property (weak, nonatomic) IBOutlet UIView *titleView;
@property (weak, nonatomic) IBOutlet UILabel *yourReceiptLbl;

@property (weak, nonatomic) IBOutlet UILabel *titleLbl;

@property (weak, nonatomic) IBOutlet UIButton *BackBtn;


@property (weak, nonatomic) IBOutlet UILabel *PriceLbl;
@property (weak, nonatomic) IBOutlet JVFloatLabeledTextField *CardNameTxt;
@property (weak, nonatomic) IBOutlet JVFloatLabeledTextField *CardNumberTxt;


@property (weak, nonatomic) IBOutlet JVFloatLabeledTextField *CVCNumberTxt;

@property (weak, nonatomic) IBOutlet JVFloatLabeledTextField *ExpDateTxt;

@property (weak, nonatomic) IBOutlet UILabel *cardNumberErrorlbl;
@property (weak, nonatomic) IBOutlet UILabel *cVCNumberErrorlbl;
@property (weak, nonatomic) IBOutlet UILabel *expDateErrorlbl;

@property (weak, nonatomic) IBOutlet UISwitch *savedCardSwitch;

@property (weak, nonatomic) IBOutlet UIButton *paymentBtn;

@property (weak, nonatomic) IBOutlet UILabel *saveCardLbl;
@property (weak, nonatomic) IBOutlet UIImageView *imageCard;



@property (weak, nonatomic) IBOutlet UIView *SaveCardView;





@end
