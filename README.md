# PayfortDemo
It is integration for ios payfort payment gateway.
================================================
Payfort ios mobile SDK integration guide
================================================

1- Integrate Payfort SKD by using drag and drop as given in Payfort ios guide. 
    Don't use any other method.
    
   Downloaded iOS SDK from official link.    
   Unzip the downloaded iOS SDK.
   Drag the PayFortSDK.framework & PayFortSDK.bundle to Frameworks in Project Navigator.
  
  Create a new group Frameworks if it does not exist.
   o Choose Create groups for any added folders.
   o Make Sure to select Copy files if needed.

2- Copy PayfortView2.xib & PayfortView2_ar.xib from the project view Or asked from Payfort support team for it,
   Now used its in your project.
   
3- User custom way for PayfortView by mapping it with PayfortView.h using Payfort framework
   Connect all outlets with your custom view.

   paycontroller?.setPayFortCustomViewNib("PayFortView2")
   
4- Download "JVFloatLabeledTextField" library from github Or use pod for it.

5- Use JVFloatLabeledTextField in place of PFKJVFloatLabeledTextField change PayfortView2.xib 
   and PayfortView2_ar.xib in "Identify Inspactor" from xcode.
   
6- Now open "PayFortView.h" from ~/PayFortSDK.framework/Header/PayFortView.h in your project 
   change outlet PFKJVFloatLabeledTextField to JVFloatLabeledTextField.

