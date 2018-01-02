//
//  HttpRequest.swift
//  PayFortDemo
//
//  Created by BHOOPENDRA SINGH on 27/12/17.
//  Copyright © 2017 BHOOPENDRA SINGH. All rights reserved.
//

import UIKit

struct HttpMethod {
    static let GET:String = "GET"
    static let POST:String = "POST"
}


class HttpRequest: NSObject {
    
    class func prepareHttpRequestWith(headers:[String:String]?,
                                      body:Data?,
                                      apiUrlStr:String!,
                                      method:String!) -> URLRequest {
        /* Preapare request url */
        let baseUrl : String = "https://sbpaymentservices.payfort.com/FortAPI/"
        let requestUrlStr : String = baseUrl.appending(apiUrlStr)
        let apiUrl = URL(string: requestUrlStr)
        
        print("Requested url = \(requestUrlStr)")
        
        /* Preapare http request */
        var request = URLRequest(url:apiUrl!)
        
        /* Set request method */
        request.httpMethod = method;
        
        /* Set request headers */
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        
        if (headers != nil) {
            //for (key, value) in headers {
            //  request.setValue(value, forHTTPHeaderField: key)
            //}
        }
        
        /* Set request body */
        if (body != nil) {
            request.httpBody = body
        }
        
        return request;
        
    }
    
}



