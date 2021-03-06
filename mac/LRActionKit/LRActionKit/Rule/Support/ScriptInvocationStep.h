@import Foundation;


@protocol ProjectContext;
@class ProjectFile;
@class RuntimeInstance;
@class LROperationResult;


typedef void (^ScriptInvocationOutputLineBlock)(NSString *line);


@interface ScriptInvocationStep : NSObject

@property(nonatomic, retain) id<ProjectContext> project;  // for collapsing the paths in the console log

@property(nonatomic, copy) NSArray *commandLine;
@property(nonatomic) LROperationResult *result;

@property(nonatomic, retain) RuntimeInstance *rubyInstance;

- (void)addValue:(id)value forSubstitutionKey:(NSString *)key;
- (void)addFileValue:(ProjectFile *)file forSubstitutionKey:(NSString *)key;

- (void)invoke;

- (ProjectFile *)fileForKey:(NSString *)key;

@property(nonatomic) BOOL finished;
@property(nonatomic, retain) NSError *error;

typedef void (^ScriptInvocationStepCompletionHandler)(ScriptInvocationStep *step);
@property(nonatomic, copy) ScriptInvocationStepCompletionHandler completionHandler;

@property(nonatomic, copy) ScriptInvocationOutputLineBlock outputLineBlock;

@end
