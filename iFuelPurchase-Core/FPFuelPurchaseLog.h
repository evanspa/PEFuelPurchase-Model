//
//  FPFuelPurchaseLog.h
//  PEFuelPurchase-Model
//
//  Created by Evans, Paul on 9/4/14.
//  Copyright (c) 2014 Paul Evans. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PELMMainSupport.h"

FOUNDATION_EXPORT NSString * const FPFplogNumGallonsField;
FOUNDATION_EXPORT NSString * const FPFplogOctaneField;
FOUNDATION_EXPORT NSString * const FPFplogGallonPriceField;
FOUNDATION_EXPORT NSString * const FPFplogGotCarWashField;
FOUNDATION_EXPORT NSString * const FPFplogCarWashPerGallonDiscountField;
FOUNDATION_EXPORT NSString * const FPFplogPurchasedAtField;

@interface FPFuelPurchaseLog : PELMMainSupport <NSCopying>

#pragma mark - Initializers

- (id)initWithLocalMainIdentifier:(NSNumber *)localMainIdentifier
            localMasterIdentifier:(NSNumber *)localMasterIdentifier
                 globalIdentifier:(NSString *)globalIdentifier
                        mediaType:(HCMediaType *)mediaType
                        relations:(NSDictionary *)relations
                        deletedAt:(NSDate *)deletedAt
                        updatedAt:(NSDate *)updatedAt
             dateCopiedFromMaster:(NSDate *)dateCopiedFromMaster
                   editInProgress:(BOOL)editInProgress
                   syncInProgress:(BOOL)syncInProgress
                           synced:(BOOL)synced
                        editCount:(NSUInteger)editCount
                 syncHttpRespCode:(NSNumber *)syncHttpRespCode
                      syncErrMask:(NSNumber *)syncErrMask
                      syncRetryAt:(NSDate *)syncRetryAt
            vehicleMainIdentifier:(NSNumber *)vehicleMainIdentifier
        fuelStationMainIdentifier:(NSNumber *)fuelStationMainIdentifier
                       numGallons:(NSDecimalNumber *)numGallons
                           octane:(NSNumber *)octane
                      gallonPrice:(NSDecimalNumber *)gallonPrice
                       gotCarWash:(BOOL)gotCarWash
         carWashPerGallonDiscount:(NSDecimalNumber *)carWashPerGallonDiscount
                      purchasedAt:(NSDate *)purchasedAt;

#pragma mark - Creation Functions

+ (FPFuelPurchaseLog *)fuelPurchaseLogWithNumGallons:(NSDecimalNumber *)numGallons
                                              octane:(NSNumber *)octane
                                         gallonPrice:(NSDecimalNumber *)gallonPrice
                                          gotCarWash:(BOOL)gotCarWash
                            carWashPerGallonDiscount:(NSDecimalNumber *)carWashPerGallonDiscount
                                         purchasedAt:(NSDate *)purchasedAt
                                           mediaType:(HCMediaType *)mediaType;

+ (FPFuelPurchaseLog *)fuelPurchaseLogWithNumGallons:(NSDecimalNumber *)numGallons
                                              octane:(NSNumber *)octane
                                         gallonPrice:(NSDecimalNumber *)gallonPrice
                                          gotCarWash:(BOOL)gotCarWash
                            carWashPerGallonDiscount:(NSDecimalNumber *)carWashPerGallonDiscount
                                         purchasedAt:(NSDate *)purchasedAt
                                    globalIdentifier:(NSString *)globalIdentifier
                                           mediaType:(HCMediaType *)mediaType
                                           relations:(NSDictionary *)relations
                                           updatedAt:(NSDate *)updatedAt;

#pragma mark - Merging

+ (NSDictionary *)mergeRemoteEntity:(FPFuelPurchaseLog *)remoteFplog
                    withLocalEntity:(FPFuelPurchaseLog *)localFplog
                  localMasterEntity:(FPFuelPurchaseLog *)localMasterFplog;

#pragma mark - Overwriting

- (void)overwriteDomainProperties:(FPFuelPurchaseLog *)fplog;

- (void)overwrite:(FPFuelPurchaseLog *)fplog;

#pragma mark - Properties

@property (nonatomic) NSNumber *vehicleMainIdentifier;

@property (nonatomic) NSString *vehicleGlobalIdentifier;

@property (nonatomic) NSNumber *fuelStationMainIdentifier;

@property (nonatomic) NSString *fuelStationGlobalIdentifier;

@property (nonatomic) NSDecimalNumber *numGallons;

@property (nonatomic) NSNumber *octane;

@property (nonatomic) NSDecimalNumber *gallonPrice;

@property (nonatomic) BOOL gotCarWash;

@property (nonatomic) NSDecimalNumber *carWashPerGallonDiscount;

@property (nonatomic) NSDate *purchasedAt;

#pragma mark - Equality

- (BOOL)isEqualToFuelPurchaseLog:(FPFuelPurchaseLog *)fuelPurchaseLog;

@end
