// Copyright 2014 Spotify
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <UIKit/UIKit.h>

@protocol SPSideTabBarDelegate;

@interface SPSideTabBar : UIView
- (id)initWithFrame:(CGRect)r;
@property(nonatomic,assign) id<SPSideTabBarDelegate> delegate; // weak reference. default is nil
@property(nonatomic,copy)   NSArray             *items;        // get/set visible UITabBarItems. default is nil. changes not animated. shown in order
@property(nonatomic,retain) UITabBarItem        *selectedItem;
@property(nonatomic,copy)   NSArray             *additionalItems; // shown starting from the bottom, not associated with a view controller

/// Background color of the tab bar. Overrides using a pattern image.
@property(nonatomic,strong) UIColor *backgroundColor;

/// Whether to round the corners of the tab bar. Spotify has it turned of since iOS7.
@property(nonatomic,assign) BOOL roundCorners;

/**
 * Use tintend images instead of a glow.
 * Spotify uses mask images to create a glow. Turning this on,
 * causes a more UITabBar-like icons.
 */
@property(nonatomic,assign) BOOL useTintedImages;

- (void)select:(BOOL)selected additionalItem:(UITabBarItem*)item;
- (CGRect)rectForItem:(UITabBarItem*)item;
- (UIButton *)buttonForTabBarItem:(UITabBarItem *)item;
@end


@protocol SPSideTabBarDelegate<NSObject>
@optional
- (void)tabBar:(SPSideTabBar *)tabBar didSelectItem:(UITabBarItem *)item; // called when a new view is selected by the user (but not programatically)
@end
