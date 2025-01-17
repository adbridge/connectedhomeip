/**
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MTRThreadOperationalDataset : NSObject

/**
 * The expected lengths of each of the NSData fields in the CHIPThreadOperationalDataset
 *
 * initWithNetworkName must be provided NSData fields with at least these lengths otherwise
 * the object will fail to init.
 */
extern size_t const MTRSizeThreadNetworkName;
extern size_t const MTRSizeThreadExtendedPanId;
extern size_t const MTRSizeThreadMasterKey;
extern size_t const MTRSizeThreadPSKc;

/**
 *  The Thread Network name
 */
@property (nonatomic, nullable, copy, readonly) NSString * networkName;
/**
 *  The Thread Network extendended PAN ID
 */
@property (nonatomic, nullable, copy, readonly) NSData * extendedPANID;
/**
 *  The 16 byte Master Key
 */
@property (nonatomic, nullable, copy, readonly) NSData * masterKey;
/**
 *  The Thread PSKc
 */
@property (nonatomic, nullable, copy, readonly) NSData * PSKc;
/**
 *  The Thread network channel.  Always an unsigned 16-bit integer.
 */
@property (nonatomic, copy, readonly) NSNumber * channelNumber MTR_NEWLY_AVAILABLE;
/**
 *  A uint16_t stored as 2-bytes in host order representing the Thread PAN ID
 */
@property (nonatomic, nullable, copy, readonly) NSData * panID;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 *  Create a Thread Operational Dataset object with the individual network fields.
 *  This initializer will return nil if any of the NSData fields don't match the expected size.
 *
 *  Note: The panID is expected to be a uint16_t stored as 2-bytes in host order
 */
- (nullable instancetype)initWithNetworkName:(NSString *)networkName
                               extendedPANID:(NSData *)extendedPANID
                                   masterKey:(NSData *)masterKey
                                        PSKc:(NSData *)PSKc
                               channelNumber:(NSNumber *)channelNumber
                                       panID:(NSData *)panID MTR_NEWLY_AVAILABLE;

/**
 *  Create a Thread Operational Dataset object with a RCP formatted active operational dataset.
 *  This initializer will return nil if the input data cannot be parsed correctly
 */
- (nullable instancetype)initWithData:(NSData *)data;

/**
 * Get the underlying data that represents the Thread Active Operational Dataset
 */
- (NSData *)data;

@end

@interface MTRThreadOperationalDataset (Deprecated)

@property (nonatomic, readwrite) uint16_t channel MTR_NEWLY_DEPRECATED("Please use channelNumber");

- (nullable instancetype)initWithNetworkName:(NSString *)networkName
                               extendedPANID:(NSData *)extendedPANID
                                   masterKey:(NSData *)masterKey
                                        PSKc:(NSData *)PSKc
                                     channel:(uint16_t)channel
                                       panID:(NSData *)panID
    MTR_NEWLY_DEPRECATED("Please use initWithNetworkName:extendedPANID:masterKey:PSKc:channelNumber:panID");

@end

NS_ASSUME_NONNULL_END
