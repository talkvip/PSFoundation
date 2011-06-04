//
//  UIViewController+MTUIAdditions.m
//  PSFoundation
//
//  Created by Matthias Tretter on 01.06.11.
//  Copyright 2011 @myell0w. All rights reserved.
//

#import "UIViewController+MTUIAdditions.h"
#import <objc/runtime.h>

////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Keys for associated objects
////////////////////////////////////////////////////////////////////////

static char oldBarButtonItemKey;


@implementation UIViewController (MTUIAdditions)

- (void)showLoadingIndicator {
    UIActivityIndicatorView *activityView = [[[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge] autorelease];
    
    activityView.autoresizingMask = UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleLeftMargin;
    activityView.center = self.view.center;
    activityView.tag = kMTActivityViewTag;
    
    [self.view addSubview:activityView];
    [activityView startAnimating];
}

- (void)hideLoadingIndicator {
    id activityView = [self.view viewWithTag:kMTActivityViewTag];
    
    if ([activityView isKindOfClass:[UIActivityIndicatorView class]]) {
        [activityView stopAnimating];
    }
    
    [activityView removeFromSuperview];
}


- (void)showLoadingIndicatorInNavigationBar {
    // initing the loading view
    UIView *backgroundView = [[[UIView alloc] initWithFrame:CGRectMake(0.f, 0.f, 24.f, 26.f)] autorelease];
    UIActivityIndicatorView *activityView = [[[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0.f, 2.f, 20.f, 20.f)] autorelease];
    
    [backgroundView addSubview:activityView];
    [activityView startAnimating];
    
    if (self.navigationItem.rightBarButtonItem != nil) {
        objc_setAssociatedObject(self, &oldBarButtonItemKey, self.navigationItem.rightBarButtonItem, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }

    self.navigationItem.rightBarButtonItem = [[[UIBarButtonItem alloc] initWithCustomView:backgroundView] autorelease];
}

- (void)hideLoadingIndicatorInNavigationBar {
    UIBarButtonItem *oldItem = (UIBarButtonItem *)objc_getAssociatedObject(self, &oldBarButtonItemKey);
    self.navigationItem.rightBarButtonItem = oldItem;
}

@end
