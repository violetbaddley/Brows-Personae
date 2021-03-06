//
//  PublicSuffixList.h
//  Brows Personæ
//
//  Created by Violet Baddley on 2015-2-27.
//  Copyright (c) 2015 Eightt. All rights reserved.
//

#import <Foundation/Foundation.h>


// This class is effectively immutable and thread-safe.


@interface PublicSuffixList : NSObject

//
// The shared singleton.
// Initializes lazily, in a threadsafe way.
+ (instancetype)suffixList;

//
// Split a domain name into its @[private, public] parts.
// The intervening dot is omitted.
// @"foo.bar.co.uk" => @[@"foo.bar", @"co.uk"]
- (NSArray *)partition:(NSString *)domain;

//
// Identify the publicly registrable part of a given domain name,
// which is the public suffix and the last label of the private portion.
// @"foo.bar.co.uk" => @"bar.co.uk"
- (NSString *)publiclyRegistrableDomain:(NSString *)domain;

//
// Ask whether a domain name has a public suffix.
// In other words, is the public partition (of the host) nonzero in length?
- (BOOL)domainHasPublicSuffix:(NSString *)domain;
- (BOOL)URLHasPublicSuffix:(NSURL *)url;

//
// Split a domain on dots.
// @"foo.bar.co.uk" => @[@"foo", @"bar", @"co", @"uk"]
- (NSArray *)domainLabels:(NSString *)domain;

@end
