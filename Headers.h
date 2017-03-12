@interface UIInteractionProgress : NSObject {
  NSPointerArray* _observers;
  double _previousPercentComplete;
  double _previousUpdateTime;
  double _mostRecentUpdateTime;
  long long _atLeastTwoUpdates;
  double _percentComplete;

}
@property (nonatomic,readonly) double percentComplete;
@property (nonatomic,readonly) double velocity;
- (id)init;
- (id)description;
- (double)percentComplete;
- (double)velocity;
- (void)addProgressObserver:(id)arg1 ;
- (void)endInteraction:(BOOL)arg1 ;
- (unsigned long long)_indexOfObserver:(id)arg1 ;
- (void)setPercentComplete:(double)arg1 ;
- (void)endInteraction:(BOOL)arg1 finalVelocity:(double)arg2 ;
- (void)removeProgressObserver:(id)arg1 ;
- (long long)numberOfObservers;
@end

@protocol UIInteractionProgressObserver <NSObject>
@optional
-(void)interactionProgressDidUpdate:(id)arg1;
-(void)interactionProgress:(id)arg1 didEnd:(BOOL)arg2;
@end

@interface SBUIForceTouchGestureRecognizer : UILongPressGestureRecognizer <UIInteractionProgressObserver> {
  double _initialMediaTime;
  UIInteractionProgress* _interactionProgress;
  BOOL _forceTouchCompleted;

}
@property (nonatomic,readonly) double pressDuration;
@property (nonatomic,readonly) BOOL forceTouchCompleted;
@property (nonatomic,readonly) double relativeTouchForce;
@property (nonatomic,readonly) double touchForceVelocity;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (copy,readonly) NSString * description;
@property (copy,readonly) NSString * debugDescription;
- (void)dealloc;
- (id)initWithTarget:(id)arg1 action:(SEL)arg2 ;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2 ;
- (void)reset;
- (void)setView:(id)arg1 ;
- (void)interactionProgress:(id)arg1 didEnd:(BOOL)arg2 ;
- (double)touchForceVelocity;
- (double)relativeTouchForce;
- (BOOL)_gestureRecognizerWillHandleTouches:(id)arg1 ;
- (BOOL)forceTouchCompleted;
- (double)pressDuration;
@end

@interface SBSApplicationShortcutItem : NSObject
@end

@interface WGWidgetViewController : UIViewController
@end

@interface SBUIAppIconForceTouchShortcutViewController : UIViewController
@end

@interface SBUIAppIconForceTouchControllerDataProvider : NSObject
@end

@interface SBUIAppIconForceTouchController : NSObject {
  SBUIAppIconForceTouchControllerDataProvider * _dataProvider;
}
- (id)_shortcutViewControllerForDataProvider:(id)arg1;
- (id)_widgetViewControllerForDataProvider:(id)arg1;
- (void)appIconForceTouchShortcutViewController:(id)arg1 activateApplicationShortcutItem:(id)arg2;
@end

@interface SBIconController : UIViewController {
  SBUIAppIconForceTouchController *_appIconForceTouchController;
}
- (_Bool)appIconForceTouchController:(id)arg1 shouldActivateApplicationShortcutItem:(id)arg2 atIndex:(unsigned long long)arg3 forGestureRecognizer:(id)arg4;
- (void)appIconForceTouchController:(id)arg1 didDismissForGestureRecognizer:(id)arg2;
- (void)appIconForceTouchController:(id)arg1 willDismissForGestureRecognizer:(id)arg2;
- (void)appIconForceTouchController:(id)arg1 didPresentForGestureRecognizer:(id)arg2;
- (void)appIconForceTouchController:(id)arg1 willPresentForGestureRecognizer:(id)arg2;
- (_Bool)appIconForceTouchController:(id)arg1 shouldHandleGestureRecognizer:(id)arg2;
- (_Bool)_iconViewInDockOrFolder:(id)arg1;
- (struct CGPoint)appIconForceTouchController:(id)arg1 zoomDownCenterForGestureRecognizer:(id)arg2;
- (id)appIconForceTouchController:(id)arg1 zoomDownViewForGestureRecognizer:(id)arg2;
- (id)appIconForceTouchController:(id)arg1 parallaxSettingsForGestureRecognizer:(id)arg2;
- (double)appIconForceTouchController:(id)arg1 iconImageCornerRadiusForGestureRecognizer:(id)arg2;
- (UIEdgeInsets)appIconForceTouchController:(id)arg1 iconImageInsetsForGestureRecognizer:(id)arg2;
- (id)appIconForceTouchController:(id)arg1 applicationShortcutItemsForGestureRecognizer:(id)arg2;
- (id)appIconForceTouchController:(id)arg1 applicationShortcutWidgetBundleIdentifierForGestureRecognizer:(id)arg2;
- (id)appIconForceTouchController:(id)arg1 applicationBundleURLForGestureRecognizer:(id)arg2;
- (id)appIconForceTouchController:(id)arg1 applicationBundleIdentifierForGestureRecognizer:(id)arg2;
- (struct CGRect)appIconForceTouchController:(id)arg1 iconViewFrameForGestureRecognizer:(id)arg2;
- (id)appIconForceTouchController:(id)arg1 newIconViewCopyForGestureRecognizer:(id)arg2;
- (_Bool)_appIconForceTouchGestureRecognizerShouldBegin;
- (void)_handleAppIconForceTouchGestureRecognizer:(id)arg1;
- (void)_dismissAppIconForceTouchControllerIfNecessaryAnimated:(_Bool)arg1 withCompletionHandler:(id)arg2;
- (_Bool)_isAppIconForceTouchControllerPeekingOrShowing;
@end