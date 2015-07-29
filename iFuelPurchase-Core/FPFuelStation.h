//
//  FPFuelStation.h
//  PEFuelPurchase-Model
//
//  Created by Evans, Paul on 9/4/14.
//  Copyright (c) 2014 Paul Evans. All rights reserved.
//

#import "PELMMainSupport.h"
#import <CoreLocation/CoreLocation.h>

@interface FPFuelStation : PELMMainSupport <NSCopying>

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
                       inConflict:(BOOL)inConflict
                        editCount:(NSUInteger)editCount
                 syncHttpRespCode:(NSNumber *)syncHttpRespCode
                      syncErrMask:(NSNumber *)syncErrMask
                      syncRetryAt:(NSDate *)syncRetryAt
                             name:(NSString *)name
                           street:(NSString *)street
                             city:(NSString *)city
                            state:(NSString *)state
                              zip:(NSString *)zip
                         latitude:(NSDecimalNumber *)latitude
                        longitude:(NSDecimalNumber *)longitude;

#pragma mark - Creation Functions

+ (FPFuelStation *)fuelStationWithName:(NSString *)name
                                street:(NSString *)street
                                  city:(NSString *)city
                                 state:(NSString *)state
                                   zip:(NSString *)zip
                              latitude:(NSDecimalNumber *)latitude
                             longitude:(NSDecimalNumber *)longitude
                             mediaType:(HCMediaType *)mediaType;

+ (FPFuelStation *)fuelStationWithName:(NSString *)name
                                street:(NSString *)street
                                  city:(NSString *)city
                                 state:(NSString *)state
                                   zip:(NSString *)zip
                              latitude:(NSDecimalNumber *)latitude
                             longitude:(NSDecimalNumber *)longitude
                      globalIdentifier:(NSString *)globalIdentifier
                             mediaType:(HCMediaType *)mediaType
                             relations:(NSDictionary *)relations
                             updatedAt:(NSDate *)updatedAt;

+ (FPFuelStation *)fuelStationWithLocalMasterIdentifier:(NSNumber *)localMasterIdentifier;

#pragma mark - Methods

- (void)overwrite:(FPFuelStation *)fuelStation;

- (CLLocation *)location;

#pragma mark - Properties

@property (nonatomic) NSString *name;

@property (nonatomic) NSString *street;

@property (nonatomic) NSString *city;

@property (nonatomic) NSString *state;

@property (nonatomic) NSString *zip;

@property (nonatomic) NSDecimalNumber *latitude;

@property (nonatomic) NSDecimalNumber *longitude;

#pragma mark - Equality

- (BOOL)isEqualToFuelStation:(FPFuelStation *)fuelStation;

@end
