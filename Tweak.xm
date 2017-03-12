#import "Headers.h"

/*
_widgetViewControllerForDataProvider: <WGWidgetViewController: 0x11de4e240>, <SBUIAppIconForceTouchControllerDataProvider: 0x17104edf0>
_shortcutViewControllerForDataProvider: <SBUIAppIconForceTouchShortcutViewController: 0x11df03190>, <SBUIAppIconForceTouchControllerDataProvider: 0x17104edf0>
*/

%hook SBIconController
- (void)_handleAppIconForceTouchGestureRecognizer:(SBUIForceTouchGestureRecognizer *)gesture {
  %orig;
  if (gesture.state == UIGestureRecognizerStateEnded) {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 3.0 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
      if ([self respondsToSelector:@selector(_dismissAppIconForceTouchControllerIfNecessaryAnimated:withCompletionHandler:)]) {
        [self _dismissAppIconForceTouchControllerIfNecessaryAnimated:YES withCompletionHandler:nil];
      }
    });

    /*
    SBUIAppIconForceTouchController *forceTouchController = nil;
    object_getInstanceVariable(self, "_appIconForceTouchController", (void **)&forceTouchController);
    if (forceTouchController == nil) {
      return;
    }
    NSArray *shortcutItems = [self appIconForceTouchController:forceTouchController applicationShortcutItemsForGestureRecognizer:gesture];
    // [self appIconForceTouchController:forceTouchController shouldActivateApplicationShortcutItem:shortcutItems[1] atIndex:1 forGestureRecognizer:gesture];

    SBUIAppIconForceTouchControllerDataProvider *dataProvider = nil;
    object_getInstanceVariable(forceTouchController, "_dataProvider", (void **)&dataProvider);
    if (dataProvider == nil) {
      return;
    }
    UIViewController *viewController = [forceTouchController _shortcutViewControllerForDataProvider:dataProvider];
    [forceTouchController appIconForceTouchShortcutViewController:viewController activateApplicationShortcutItem:shortcutItems[0]];
    */
  }
}
%end