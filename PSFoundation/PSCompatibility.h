//
//  PSCompatibility.h
//  PSFoundation
//
//  Created by Peter Steinberger on 09.09.10.
//  Licensed under MIT. All rights reserved.
//
//  References:
//   - http://blancer.com/tutorials/i-phone/72236/tips-tricks-for-conditional-ios3-ios3-2-and-ios4-code/
//

#import "UIDevice+PSFoundation.h"

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_2_0
#define kCFCoreFoundationVersionNumber_iPhoneOS_2_0 478.23
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_2_1
#define kCFCoreFoundationVersionNumber_iPhoneOS_2_1 478.26
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_2_2
#define kCFCoreFoundationVersionNumber_iPhoneOS_2_2 478.29
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_3_0
#define kCFCoreFoundationVersionNumber_iPhoneOS_3_0 478.47
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_3_1
#define kCFCoreFoundationVersionNumber_iPhoneOS_3_1 478.52
#endif

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_3_2
#define kCFCoreFoundationVersionNumber_iPhoneOS_3_2 478.61
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_4_0
#define kCFCoreFoundationVersionNumber_iOS_4_0 550.32
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_4_1
#define kCFCoreFoundationVersionNumber_iOS_4_1 550.38
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_4_2
#define kCFCoreFoundationVersionNumber_iOS_4_2 550.52
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_5_0
#define kCFCoreFoundationVersionNumber_iOS_5_0 661.00
#endif

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 50000
#define IF_IOS5_OR_GREATER(...) \
if (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iOS_5_0) { \
__VA_ARGS__ \
}
#define IS_GTE_IOS5 (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iOS_5_0)
#else
#define IF_IOS5_OR_GREATER(...)
#define IS_GTE_IOS5 0
#endif

#define IF_PRE_5_0(...) \
if (kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_iOS_5_0) { \
__VA_ARGS__ \
}
#define IS_LT_IOS50 (kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_iOS_5_0)

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 40200
#define IF_IOS42_OR_GREATER(...) \
if (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iOS_4_2) { \
__VA_ARGS__ \
}
#define IS_GTE_IOS42 (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iOS_4_2)
#define IS_GT_IOS42 (kCFCoreFoundationVersionNumber > kCFCoreFoundationVersionNumber_iOS_4_2)
#else
#define IF_IOS42_OR_GREATER(...)
#define IS_GTE_IOS42 0
#define IS_GT_IOS42 0
#endif

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 40000
#define IF_IOS4_OR_GREATER(...) \
if (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iOS_4_0) { \
__VA_ARGS__ \
}
#define IS_GTE_IOS4 (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iOS_4_0)
#else
#define IF_IOS4_OR_GREATER(...)
#define IS_GTE_IOS4 0
#endif

#define IF_PRE_IOS4(...)  \
if (kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_iOS_4_0) { \
__VA_ARGS__ \
}
#define IS_LT_IOS4 (kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_iOS_4_0)

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 32000
#define IF_3_2_OR_GREATER(...) \
if (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iPhoneOS_3_2) { \
__VA_ARGS__ \
}
#define IS_GTE_IOS32 (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iPhoneOS_3_2)
#else
#define IF_3_2_OR_GREATER(...)
#define IS_GTE_IOS32 0
#endif

#define IF_PRE_3_2(...) \
if (kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_iPhoneOS_3_2) { \
__VA_ARGS__ \
}
#define IS_LT_IOS32 (kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_iPhoneOS_3_2)

// special addition for Chameleon support: http://chameleonproject.org/
#if TARGET_IPHONE_SIMULATOR
#define IS_IOS 1
#define IS_MAC 0
#define IF_IOS(...) do {__VA_ARGS__} while(0);
#define IF_DESKTOP(...)
#elif TARGET_OS_IPHONE
#define IS_IOS 1
#define IS_MAC 0
#define IF_IOS(...) do {__VA_ARGS__} while(0);
#define IF_DESKTOP(...)
#else
#define IS_IOS 0
#define IS_MAC 1
#define IF_IOS(...)
#define IF_DESKTOP(...) do {__VA_ARGS__} while(0);
#endif

#define isIPad() [[UIDevice currentDevice] isTablet]

#define PS_HAS_ARC __has_feature(objc_arc)


#if PS_HAS_ARC
    #define PS_AUTORELEASEPOOL(...) @autoreleasepool { do {__VA_ARGS__;} while(0); }
    #define PS_DO_RETAIN(o)
    #define PS_RETAIN(o) o
    #define PS_DO_AUTORELEASE(o)
    #define PS_AUTORELEASE(o) o
    #define PS_DEALLOC()
    #define __ps_unsafe_unretained __unsafe_unretained
    #define __ps_autoreleasing __autoreleasing
    #define __ps_strong __strong
    #define __ps_weak __weak
    #define ps_weak weak
    #define ps_strong strong
    #define PS_RETURN_AUTORELEASED(...) do { \
    id __autoreleasing instance = __VA_ARGS__; \
    return instance; \
    } while (0)
    #define ps_retainedObject objc_retainedObject
    #define ps_unretainedObject objc_unretainedObject
    #define ps_unretainedPointer objc_unretainedPointer
#else
    #define PS_AUTORELEASEPOOL(...) NSAutoreleasePool *pool = [NSAutoreleasePool new]; do {__VA_ARGS__;} while(0); [pool drain]
    #define PS_RETAIN(o) [o retain]
    #define PS_DO_RETAIN(o) [o retain]
    #define PS_AUTORELEASE(o) [o autorelease]
    #define PS_DO_AUTORELEASE(o) [o autorelease]
    #define PS_DEALLOC() [super dealloc]
    #define __ps_unsafe_unretained
    #define __ps_autoreleasing
    #define __ps_strong
    #define __ps_weak
    #define ps_weak assign
    #define ps_strong retain
    #define PS_RETURN_AUTORELEASED(...) do { \
    return [__VA_ARGS__ autorelease]; \
    } while (0)

    static __inline NS_RETURNS_RETAINED id __ps_objc_retainedObject(void *CF_CONSUMED pointer) { return (id)pointer; }
    static __inline NS_RETURNS_NOT_RETAINED id __ps_objc_unretainedObject(void *pointer) { return (id)pointer; }
    static __inline CF_RETURNS_NOT_RETAINED void *__ps_objc_unretainedPointer(id object) { return (void *)object; }
    #define ps_retainedObject __ps_objc_retainedObject
    #define ps_unretainedObject __ps_objc_unretainedObject
    #define ps_unretainedPointer __ps_objc_unretainedPointer
#endif