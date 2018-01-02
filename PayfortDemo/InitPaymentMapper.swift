//
//  InitPaymentMapper.swift
//  PayFortDemo
//
//  Created by BHOOPENDRA SINGH on 27/12/17.
//  Copyright © 2017 BHOOPENDRA SINGH. All rights reserved.
//

import ObjectMapper

class InitPaymentMapper: Mappable {
    public var status:String?
    public var message:String?
    public var code:String?
    public var data:Any?
    
    required init?(map: Map) {
        
    }
    
    func mapping(map: Map) {
        print("UnitsTypeMapper:Mapping");
        
        status  <- map["status"]
        message <- map["msg"]
        code    <- map["code"]
        data    <- map["data"]
    }
}

