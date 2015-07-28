//
//  FPErrorDomainsAndCodes.h
//  PEFuelPurchase-Model
//
//  Created by Evans, Paul on 8/18/14.
//  Copyright (c) 2014 Paul Evans. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Error domain for errors that are fundamentally the fault of the user (e.g.,
 providing invalid input).
 */
FOUNDATION_EXPORT NSString * const FPUserFaultedErrorDomain;

/**
 Error domain for errors that are fundamentally connection-related (neither the
 fault of the user, or the backend system.  The error codes used for this
 domain are listed here:
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Miscellaneous/Foundation_Constants/Reference/reference.html
 This error domain effectively mirrors the NSURLErrorDomain domain.
 */
FOUNDATION_EXPORT NSString * const FPConnFaultedErrorDomain;

/**
 Error domain for errors that are fundamentally the fault of the system (e.g.,
 the database is down).
 */
FOUNDATION_EXPORT NSString * const FPSystemFaultedErrorDomain;

/**
 Error codes for the 'Save User' use cases of the FPUserFaultedErrorDomain
 domain.
 */
typedef NS_OPTIONS(NSUInteger, FPSaveUserMsg) {
  FPSaveUsrAnyIssues                   = 1 << 0,
  FPSaveUsrInvalidEmail                = 1 << 1,
  FPSaveUsrUsernameAndEmailNotProvided = 1 << 2,
  FPSaveUsrPasswordNotProvided         = 1 << 3,
  FPSaveUsrEmailAlreadyRegistered      = 1 << 4,
  FPSaveUsrUsernameAlreadyRegistered   = 1 << 5
};

/**
 Error codes for the 'Save Environment Log' use cases of the FPUserFaultedErrorDomain
 domain.
 */
typedef NS_OPTIONS(NSUInteger, FPSaveEnvironmentLogMsg) {
  FPSaveEnvironmentLogAnyIssues                 = 1 << 0,
  FPSaveEnvironmentLogDateNotProvided           = 1 << 1,
  FPSaveEnvironmentLogOdometerNotProvided       = 1 << 2,
  FPSaveEnvironmentLogOutsideTempNotProvided    = 1 << 3,
  FPSaveEnvironmentLogOdometerNegative          = 1 << 4,
  FPSaveEnvironmentLogUserDoesNotExist          = 1 << 5,
  FPSaveEnvironmentLogVehicleDoesNotExist       = 1 << 6
};

/**
 Error codes for the 'Save Fuel Purchase Log' use cases of the FPUserFaultedErrorDomain
 domain.
 */
typedef NS_OPTIONS(NSUInteger, FPSaveFuelPurchaseLogMsg) {
  FPSaveFuelPurchaseLogAnyIssues                 = 1 << 0,
  FPSaveFuelPurchaseLogPurchaseDateNotProvided   = 1 << 1,
  FPSaveFuelPurchaseLogNumGallonsNotProvided     = 1 << 2,
  FPSaveFuelPurchaseLogOctaneNotProvided         = 1 << 3,
  FPSaveFuelPurchaseLogGallonPriceNotProvided    = 1 << 4,
  FPSaveFuelPurchaseLogGallonPriceNegative       = 1 << 5,
  FPSaveFuelPurchaseLogNumGallonsNegative        = 1 << 6,
  FPSaveFuelPurchaseLogOctaneNegative            = 1 << 7,
  FPSaveFuelPurchaseLogUserDoesNotExist          = 1 << 8,
  FPSaveFuelPurchaseLogVehicleDoesNotExist       = 1 << 9,
  FPSaveFuelPurchaseLogFuelStationDoesNotExist   = 1 << 10
};

/**
 Error codes for the 'Save Fuel Station' use cases of the FPUserFaultedErrorDomain
 domain.
 */
typedef NS_OPTIONS(NSUInteger, FPSaveFuelStationMsg) {
  FPSaveFuelStationAnyIssues                 = 1 << 0,
  FPSaveFuelStationNameNotProvided           = 1 << 1, // ctx: Create/Edit fuel station
  FPSaveFuelStationUserDoesNotExist          = 1 << 2
};

/**
 Error codes for the 'Save Vehicle' use cases of the FPUserFaultedErrorDomain
 domain.
 */
typedef NS_OPTIONS(NSUInteger, FPSaveVehicleMsg) {
  FPSaveVehicleAnyIssues              = 1 << 0,
  FPSaveVehicleNameNotProvided        = 1 << 1, // ctx: Create/Edit vehicle
  FPSaveVehicleVehicleAlreadyExists   = 1 << 2, // ctx: Create vehicle
  FPSaveVehicleNameContainsPurple     = 1 << 3,
  FPSaveVehicleNameContainsRed        = 1 << 4,
  FPSaveVehicleUserDoesNotExist       = 1 << 5
};

/**
 General (screen-agnostic) error codes of the FPSystemFaultedErrorDomain domain.
 */
typedef NS_OPTIONS(NSUInteger, FPSysErrorMsg) {
  FPSysAnyIssues    = 1 << 0,
  FPSysDatabaseDown = 1 << 1
};

/**
 Error codes for the 'Sign In' use case of the FPUserFaultedErrorDomain
 domain.
 */
typedef NS_OPTIONS(NSUInteger, FPSignInMsg) {
  FPSignInAnyIssues                  = 1 << 0,
  FPSignInUsernameOrEmailNotProvided = 1 << 1,
  FPSignInPasswordNotProvided        = 1 << 2,
  FPSignInInvalidCredentials         = 1 << 3
};

