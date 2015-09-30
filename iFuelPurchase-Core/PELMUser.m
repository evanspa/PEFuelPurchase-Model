//
//  PELMUser.m
//  PEFuelPurchase-Model
//
//  Created by Evans, Paul on 2/27/15.
//  Copyright (c) 2015 Paul Evans. All rights reserved.
//

#import "PELMUser.h"
#import <PEObjc-Commons/PEUtils.h>
#import "FPDDLUtils.h"

NSString * const PELMUsersRelation = @"users";
NSString * const PELMLoginRelation = @"login";
NSString * const PELMLightLoginRelation = @"light-login";
NSString * const PELMLogoutRelation = @"logout";
NSString * const PELMSendVerificationEmailRelation = @"send-verification-email";

@implementation PELMUser

#pragma mark - Initializers

- (id)initWithLocalMainIdentifier:(NSNumber *)localMainIdentifier
            localMasterIdentifier:(NSNumber *)localMasterIdentifier
                 globalIdentifier:(NSString *)globalIdentifier
                        mediaType:(HCMediaType *)mediaType
                        relations:(NSDictionary *)relations
                        createdAt:(NSDate *)createdAt
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
                             name:(NSString *)name
                            email:(NSString *)email
                         password:(NSString *)password
                       verifiedAt:(NSDate *)verifiedAt {
  self = [super initWithLocalMainIdentifier:localMainIdentifier
                      localMasterIdentifier:localMasterIdentifier
                           globalIdentifier:globalIdentifier
                            mainEntityTable:TBL_MAIN_USER
                          masterEntityTable:TBL_MASTER_USER
                                  mediaType:mediaType
                                  relations:relations
                                  createdAt:createdAt
                                  deletedAt:deletedAt
                                  updatedAt:updatedAt
                       dateCopiedFromMaster:dateCopiedFromMaster
                             editInProgress:editInProgress
                             syncInProgress:syncInProgress
                                     synced:synced
                                  editCount:editCount
                           syncHttpRespCode:syncHttpRespCode
                                syncErrMask:syncErrMask
                                syncRetryAt:syncRetryAt];
  if (self) {
    _name = name;
    _email = email;
    _password = password;
    _verifiedAt = verifiedAt;
  }
  return self;
}

#pragma mark - NSCopying

-(id)copyWithZone:(NSZone *)zone {
  PELMUser *copy = [[PELMUser alloc] initWithLocalMainIdentifier:[self localMainIdentifier]
                                           localMasterIdentifier:[self localMasterIdentifier]
                                                globalIdentifier:[self globalIdentifier]
                                                       mediaType:[self mediaType]
                                                       relations:[self relations]
                                                       createdAt:[self createdAt]
                                                       deletedAt:[self deletedAt]
                                                       updatedAt:[self updatedAt]
                                            dateCopiedFromMaster:[self dateCopiedFromMaster]
                                                  editInProgress:[self editInProgress]
                                                  syncInProgress:[self syncInProgress]
                                                          synced:[self synced]
                                                       editCount:[self editCount]
                                                syncHttpRespCode:[self syncHttpRespCode]
                                                     syncErrMask:[self syncErrMask]
                                                     syncRetryAt:[self syncRetryAt]
                                                            name:_name
                                                           email:_email
                                                        password:_password
                                                      verifiedAt:_verifiedAt];
  return copy;
}

#pragma mark - Creation Functions

+ (PELMUser *)userWithName:(NSString *)name
                     email:(NSString *)email
                  password:(NSString *)password
                 mediaType:(HCMediaType *)mediaType {
  return [PELMUser userWithName:name
                          email:email
                       password:password
                     verifiedAt:nil
               globalIdentifier:nil
                      mediaType:mediaType
                      relations:nil
                      createdAt:nil
                      deletedAt:nil
                      updatedAt:nil];
}

+ (PELMUser *)userWithName:(NSString *)name
                     email:(NSString *)email
                  password:(NSString *)password
                verifiedAt:(NSDate *)verifiedAt
          globalIdentifier:(NSString *)globalIdentifier
                 mediaType:(HCMediaType *)mediaType
                 relations:(NSDictionary *)relations
                 createdAt:(NSDate *)createdAt
                 deletedAt:(NSDate *)deletedAt
                 updatedAt:(NSDate *)updatedAt {
  return [[PELMUser alloc] initWithLocalMainIdentifier:nil
                                 localMasterIdentifier:nil
                                      globalIdentifier:globalIdentifier
                                             mediaType:mediaType
                                             relations:relations
                                             createdAt:createdAt
                                             deletedAt:deletedAt
                                             updatedAt:updatedAt
                                  dateCopiedFromMaster:nil
                                        editInProgress:NO
                                        syncInProgress:NO
                                                synced:NO
                                             editCount:0
                                      syncHttpRespCode:nil
                                           syncErrMask:nil
                                           syncRetryAt:nil
                                                  name:name
                                                 email:email
                                              password:password
                                            verifiedAt:verifiedAt];
}

#pragma mark - Methods

- (void)overwrite:(PELMUser *)user {
  [super overwrite:user];
  [self setName:[user name]];
  [self setEmail:[user email]];
  [self setPassword:[user password]];
  [self setVerifiedAt:[user verifiedAt]];
}

#pragma mark - Equality

- (BOOL)isEqualToUser:(PELMUser *)user {
  if (!user) { return NO; }
  if ([super isEqualToMainSupport:user]) {
    return [PEUtils isString:[self name] equalTo:[user name]] &&
    [PEUtils isString:[self email] equalTo:[user email]] &&
    [PEUtils isString:[self password] equalTo:[user password]] &&
    [PEUtils isDate:[self verifiedAt] equalTo:[user verifiedAt]];
  }
  return NO;
}

#pragma mark - NSObject

- (BOOL)isEqual:(id)object {
  if (self == object) { return YES; }
  if (![object isKindOfClass:[PELMUser class]]) { return NO; }
  return [self isEqualToUser:object];
}

- (NSUInteger)hash {
  return [super hash] ^
  [[self name] hash] ^
  [[self email] hash] ^
  [[self password] hash] ^
  [[self verifiedAt] hash];
}

- (NSString *)description {
  return [NSString stringWithFormat:@"%@, name: [%@], email: [%@], \
password: [%@], verified-at: [%@]",
          [super description],
          _name, _email, _password, _verifiedAt];
}

@end
