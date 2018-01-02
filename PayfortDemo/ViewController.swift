//
//  ViewController.swift
//  PayFortDemo
//
//  Created by BHOOPENDRA SINGH on 26/12/17.
//  Copyright © 2017 BHOOPENDRA SINGH. All rights reserved.
//

import UIKit
import Alamofire
import CryptoSwift

class ViewController: UIViewController {
    let paycontroller = PayFortController.init(enviroment: KPayFortEnviromentSandBox)
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //if you need to switch on the Payfort Response page
        paycontroller?.isShowResponsePage = true
        paycontroller?.setPayFortCustomViewNib("PayFortView2")
        createApiRequestForInitPayment ()
        
    }
    
    
    func createApiRequestForInitPayment() {
        
        do {
            let bodyDict:[String:Any] = getRequestBody()
            let jsonData = try JSONSerialization.data(withJSONObject: bodyDict, options: .prettyPrinted)
            let request: URLRequest = HttpRequest.prepareHttpRequestWith(headers:nil,
                                                                         body:jsonData,
                                                                         apiUrlStr:"paymentApi",
                                                                         method:HttpMethod.POST)
            
            ProgressHUD.showProgressHud(message: "Wait...", view: self.view)
            
            Alamofire.request(request).responseJSON(completionHandler: { (response: DataResponse<Any>) -> () in
                print(response)
                ProgressHUD.hideProgressHud(view: self.view)
                self.createPaymentApiRequest(response: response.result.value)
            })
            
            //            Alamofire.request(request).responseObject { (response: DataResponse<InitPaymentMapper>) in
            //                ProgressHUD.hideProgressHud(view: self.view)
            //
            //                guard let aPIModel: InitPaymentMapper = response.result.value else {
            //                    Utility.showOkAlertView(title: Message.kMessage, message: "Something went wrong!", viewCtrl: self)
            //
            //                    return
            //                }
            //
            //                if (aPIModel.data != nil && aPIModel.code == "200") {
            //                    let number:Float = (aPIModel.data?.estimatedCost)!
            //                    self.estimatedCost = String(number)
            //                }
            //                else {
            //                    print("Failure response")
            //                }
            //
            //
            //            }
            
        } catch let error as NSError {
            print(error.localizedDescription)
        }
        
    }
    
    
    func getRequestBody() -> [String:Any] {
        let payloadDict = NSMutableDictionary()
        payloadDict.setValue("en", forKey:"language" )
        payloadDict.setValue("pCeAAeCX", forKey: "merchant_identifier")
        payloadDict.setValue("BB9WQcrYUYSYUSD32wS8g", forKey:"access_code" )
        payloadDict.setValue("SDK_TOKEN", forKey:"service_command" )
        
        let deviceID = UIDevice.current.identifierForVendor!.uuidString
        payloadDict.setValue(deviceID, forKey:"device_id")
        
        let paymentString = "TESTSHAINaccess_code=BB9WQcrYUYSYUSD32wS8ggdevice_id=\(deviceID)language=enmerchant_identifier=pMpPPeCXservice_command=SDK_TOKENTESTSHAIN"
        
        
        let base64Str = paymentString.sha256()
        payloadDict.setValue(base64Str, forKey:"signature")
        
        return payloadDict as! [String : Any]
        
    }
    
    
    func createPaymentApiRequest(response:Any?) {
        if (response != nil) {
            let responseDict = response as! NSDictionary
            let tokenStr = responseDict["sdk_token"] as! String
            let marchantRefStr = responseDict["merchant_identifier"] as! String
            
            let payloadDict = NSMutableDictionary.init()
            payloadDict.setValue(tokenStr , forKey: "sdk_token")
            payloadDict.setValue("1000", forKey: "amount")
            payloadDict.setValue("AUTHORIZATION", forKey: "command")
            payloadDict.setValue("AED", forKey: "currency")
            payloadDict.setValue("abcxxxx@damacgroup.com", forKey: "customer_email")
            payloadDict.setValue("en", forKey: "language")
            payloadDict.setValue(marchantRefStr, forKey: "merchant_reference")
            payloadDict.setValue("VISA" , forKey: "payment_option")
            
            
            paycontroller?.callPayFort(withRequest: payloadDict, currentViewController: self,
                                       success: { (requestDic, responeDic) in
                                        
                                        print("Success:\(String(describing: responeDic))")
                                        
            },
                                       canceled: { (requestDic, responeDic) in
                                        
                                        print("Canceled:\(String(describing: responeDic))")
                                        
            },
                                       faild: { (requestDic, responeDic, message) in
                                        
                                        print("Failure:\(String(describing: responeDic))")
                                        print("Failure message:\(String(describing: message))")
                                        
            })
        }
    }
    
}


