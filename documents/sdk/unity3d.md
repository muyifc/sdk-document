## Unity3D GASDK文档

## 1.下载SDK

 1.1 [渠道母包](http://docs.mztgame.com/files/unity3d/GiantSDK_1.0.0_170321.zip)

 ***母包插件说明:***

 >ios 含巨人官方渠道资源，有UI界面，导出工程可以直接使用

 >android 不含巨人官方资源，导出无UI界面，需要用平台打包工具，出各渠道包。

 >适合上国内渠道的游戏

 1.2 [巨人官方渠道资源](http://docs.mztgame.com/files/unity3d/Android_1.0_官方资源.zip)

  ***巨人官方说明:***

> 压缩文件有README.txt,有替换说明，请查看。

> 替换android资源，iOS不用修改，可以出巨人官方渠道 .


## 2.系统配置
   1.复制下面的目录
    AppendFile/
    SDKFile/
    拷贝全部到  Assets 同级目录
    ![配置说明](http://docs.mztgame.com/files//assets/unityimg/giant_sdk_config.png)


   2.初始化接口，注册回调事件接口，只能执行一次，使用状态值判定 或 是放至单例脚本的Awake或Start函数中.
   示例
   
```CSharp
   public static bool isStart = false;
   void Start()
   {
       if (!isStart)
       {
           isStart = true;
           GiantSDKPlatformManager.OnLoginComplete += (retCode,  json) =>{
 			          Debug.Log( " 登录成功  In C# Client ret = "+retCode + ",json = " +json

                  });
       }
   }
   
```
   
   3.如果替换官方资源后，而且需要开通微信支付  可以导出源码后，手动拷贝，wxapi源码文件名必须为WXPayEntryActivity.java，目录必须为wxapi。


## 3.基本API

### 3.1初始化接口

*1.接口说明*

初始化SDK,在其他接口之前调用。

*2.函数原型*


```
 //初始化 【游戏ID[需要向巨人平台申请]，游戏名字,true横屏 false 竖屏) 】
 void InitGASDK(string gameid,string appName,bool isLandScape);

```

| 参数        | 类型           | 意义   |
| ------------- |:-------------:| -----:|
| appId      | string | 游戏ID[需要向巨人平台申请] |
| appName     | string      |   游戏名字|
| isLandScape | bool    |  true横屏 false 竖屏|

*3调用例子*

```
  GiantSDKPlatformManager.basePlatform.InitGASDK("5014","testGameName",false);

```


### 3.2 登录接口

*1.接口说明*

  请求登录接口

*2.函数原型*

```
  //登录【是否自动登录（true自动登录，false不自动登录）】
  void Login(bool isAutoLogin);

```    
| 参数        | 类型           | 意义   |
| ------------- |:-------------:| -----:|
| isAutoLogin | bool    |  true自动登录，false不自动登录|

 *3调用举例*

```
  GiantSDKPlatformManager.basePlatform.Login(true);

```


### 3.3 支付接口

*1.接口说明*

  请求支付接口

*2.函数原型*

```
  //支付（参考支付类参数）
  void Pay(GAPayInfo payInfo);

```    
| 参数        | 类型           | 意义   |
| ------------- |:-------------:| -----:|
| payInfo | GAPayInfo    |  支付实体类|

 *3调用举例*
```

GiantSDKPlatformManager.basePlatform.Pay (new GAPayInfo("zonId","productId","productName",100,1,1,""));

```

参数说明：  
支付类参数：
```
public class GAPayInfo{

 public string zoneId;//区ID （必填）
 public string productId;//商品id （必填）
 public string productName;// 商品名字 （必填）
 public int productPrice;// 商品价格 （必填）
 public int productCount; // 商品数量 （必填）
 public int exchangeRate = 1; // 商品兑换比例 （默认是1）
 public string extra ;// 拓展信息 （可为空）

 }
```

### 3.4 切换账号

*1.接口说明*

  切换账号

*2.函数原型*

```

//切换账号
   void SwitchUser();

```

 *3调用举例*


调用实例：可参考demo

```
GiantSDKPlatformManager.basePlatform.SwitchUser();
```
### 3.5 用户中心
*1.接口说明*

  请求支付接口

*2.函数原型*

```
//用户中心
  void UserCenter();

```    

 *3调用举例*

```
  GiantSDKPlatformManager.basePlatform.UserCenter();
```

###  3.6 开启日志输出接口

*1.接口说明*

  开启日志输出接口

*2.函数原型*

```
  //开启日志输出接口   游戏上线前需要注释该行代码以关闭日志输出
  void EnableDebugGA();

```    

 *3调用举例*

```
  GiantSDKPlatformManager.basePlatform.EnableDebugGA();
```


### 3.7 是否需要用户中心按钮接口
*1.接口说明*

  渠道是否有用户中心

*2.函数原型*

```

 //渠道是否有用户中心
 bool HasUserCenter()

```    
  
| 类型           | 意义   |
|:-------------:| -----:|
| bool | true需要显示*用户中心按钮,false 不做处理|

 *3调用举例*

```
  GiantSDKChannelManager.baseChannel.HasUserCenter();
```
### 3.8 是否需要切换账号按钮接口
*1.接口说明*

  渠道是否需要切换账号按钮接口

*2.函数原型*

```

 //是否需要切换账号按钮接口
 bool HasSwitchUser()

``` 
| 类型           | 意义   |
|:-------------:| -----:|
| bool | true则游戏需要添加一个切换账号按钮,false 不做处理|

 *3调用举例*

```
   GiantSDKPlatformManager.baseChannel.HasSwitchUser();
```

###  3.9 是否有第三方渠道的退出确认弹出框
*1.接口说明*

  渠道是否有第三方渠道的退出确认弹出框

*2.函数原型*

```

 //是否有第三方渠道的退出确认弹出框
 bool HasQuitDialog();

```    

 *3调用举例*

```
  GiantSDKChannelManager.baseChannel.HasQuitDialog();
```

### 3.10 弹出第三方退出弹出框 确认按钮接口
*1.接口说明*

  渠道弹出第三方退出弹出框 确认按钮

*2.函数原型*

```

 //是否有第三方渠道的退出确认弹出框
 void QuitGameBtn();

```    

 *3调用举例*


```
   GiantSDKChannelManager.baseChannel.QuitGameBtn();
```

### 3.11获取渠道ID
*1.接口说明*

  获取渠道id

*2.函数原型*

```

 //获取渠道id
 int GetPlatFormId();

```    
 | 类型           | 意义   |
 |:-------------:| -----:|
  int | 渠道的id|

 *3调用举例*

```
   GiantSDKChannelManager.baseChannel.GetPlatFormId();
```
### 3.12更新服务器ID
*1.接口说明*

  更新服务器ID

*2.函数原型*

```

 //更新服务器ID,玩家切换服务器后需要调用此方法更新当前服务器id
 void SetZoneId();

```    

 *3调用举例*

```
  GiantSDKChannelManager.basePlatform.SetZoneId("11");
```
### 3.13更新当前活动Activity

*1.接口说明*

  更新当前活动Activity

*2.函数原型*

```

 //更新当前活动Activity,如果游戏当前Activity变更，需要更新activity到SDK
 void SetActivity();

```    

 *3调用举例*

```
   GiantSDKChannelManager.baseChannel.SetActivity();
```
### 3.14 是否已经登录
*1.接口说明*

  是否已经登录

*2.函数原型*

```

 //更新当前活动Activity,如果游戏当前Activity变更，需要更新activity到SDK
 bool IsLogined();

```    
 | 类型           | 意义   |
 |-------------:| -----:|
 | bool | true :已经登录，false 没有登录|
 *3调用举例*

```
   GiantSDKChannelManager.baseChannel.IsLogined();
```
### 3.15登录完成数据统计接口
*1.接口说明*

  登录完成数据统计接口

*2.函数原型*

```

 //登录完成数据统计接口,角色进入游戏后调用
 void LoginOkZTGame(string roleId,string roleName, string roleLevel,string zoneId, string zoneName);

```    
| 参数        | 类型           | 意义   |
| ------------- |:-------------:| -----:|
| roleId      | string | 角色id |
| roleName     | string      |  角色名字|
| roleLevel | string    |  角色等级|
| zoneId     | string      |   区ID|
| zoneName | string    |  区名|

 *3调用举例*

```
 GiantSDKChannelManager.baseChannel.LoginOkZTGame("1","角色名","角色等级","11","区名");
```
### 3.16创建角色数据统计接口
*1.接口说明*

  创建角色数据统计接口

*2.函数原型*

```

 //创建角色数据统计接口
 void CreateRoleZTGame(string roleId,string roleName, string roleLevel,string zoneId, string zoneName);

```    
| 参数        | 类型           | 意义   |
| ------------- |:-------------:| -----:|
| roleId      | string | 角色id |
| roleName     | string      |  角色名字|
| roleLevel | string    |  角色等级|
| zoneId     | string      |   区ID|
| zoneName | string    |  区名|

 *3调用举例*

```
  GiantSDKChannelManager.baseChannel.CreateRoleZTGame("1", "角色名", "角色等级", "11", "区名");
```
### 3.17角色等级升级信息接口
*1.接口说明*

  角色等级升级信息接口

*2.函数原型*

```

 //创建角色数据统计接口
 void RoleLevelUpZTGame(string roleId,string roleName, string zoneId,string zoneName, int level);

```    
| 参数        | 类型           | 意义   |
| ------------- |:-------------:| -----:|
| roleId      | string | 角色id |
| roleName     | string      |  角色名字|
| level | int    |  角色等级|
| zoneId     | string      |   区ID|
| zoneName | string    |  区名|
 *3调用举例*


```
   GiantSDKChannelManager.baseChannel.RoleLevelUpZTGame("1", "角色名",  "11", "区名",11);
```
### 3.18 登录回调
*1.接口说明*

  登录回调

*2.函数原型*

```

 //登录回调
 public delegate void LoginCompleteHandler (int retCode, string json);

```    
| 参数        | 类型           | 意义   |
| ------------- |:-------------:| -----:|
| retCode      | int | 0 成功，1 失败  -1 错误。 |
| json     | string      |  登录信息|

```json
{
    "account" : "4f*****sm",
     
    "sign" : "a\/wE7oX8hx6TEjCfsTm4ziqQjkV51WmRoNOLmud0W5XDohsiL\/WHpcOoMKE72yTrD+mADgUTD31Bfmnthb83AZmCcNcnGU4zg5eWbH3lNEMYwTsIDUxYrm9L6GBf18BaRdWNDSVSo20Qd2ckoer0dUzsSDbCKAXw48UyjX5kgEY\/dBW5PwwWWs+nM7vCJqiFMHKtx3RdJAvhDsIeJpL7xdQo5gzdXRi4qRqzAUyDnAvB1QdpcEwoZ3R\/XbKmiWIBbFBhZTqztLc65s8sD5ZBSVMrkSfuuxXNO2TiyV8LvomCZNwqcE2ks5wCLGUAmIX87ZW5vmgn5deUYsxcoGHSxg==",
    "entity" : {
      "time" : 1482983893,
      "account" : "_q_4ff8apgsm",
      "openid" : "1-1990027331"
    },
    "accid" : "1-1990027331",
    "token" : "uc18c22521fde898a92e7fcb20oixhp1",
    .....
  }

```

 >accid 为账号唯一身份标识, 即服务端的 openid; account 可能为空;

 *3调用举例*

```
GiantSDKPlatformManager.OnLoginComplete += (retCode,  json) =>{
    Debug.Log( " 登录  In C# Client ret = "+retCode + ",json = " +json
    );

  };
```

### 3.19 支付回调
*1.接口说明*

  支付回调

*2.函数原型*

```

   //支付回调
   public delegate void PayCompleteHanlder (int retCode);

```    
| 参数        | 类型           | 意义   |
| ------------- |:-------------:| -----:|
| retCode      | int | 0 成功，其他状态默认失败  |

*3调用举例*

```
GiantSDKPlatformManager.OnPayComplete += ( retCode) =>{
			Debug.Log("  支付  In C# Client ret = " + retCode  );

		};
```



### 3.20 渠道退出消息
*1.接口说明*

  渠道退出消息

*2.函数原型*

```

//确认退出按钮
public delegate void QuitGameButtonCompleteHandler (int retcode);

```    
| 参数        | 类型           | 意义   |
| ------------- |:-------------:| -----:|
| retcode      | int | retcode :4 , 退出成功|

*3调用举例*

```
GiantSDKChannelManager.OnQuitGameButtonComplete += (retcode)=>{
			Debug.Log("  第三方弹出框  确认按钮In C# Client ret = " + retcode);
		};

```



 
## 4 生命周期配置(渠道母包)
  *4.1 在游戏的主Activity加入下面生命周期
  
```
<activity
        android:name="com.giant.sdk.unity.GiantSDKActivity"
        android:theme="@android:style/Theme.NoTitleBar.Fullscreen"
        android:configChanges="orientation|keyboardHidden|screenSize"
        android:screenOrientation=" 填写相应方向portrait(竖屏) or landscape(横屏)">
        <intent-filter>
            <action android:name="android.intent.action.MAIN" />
            <category android:name="android.intent.category.LAUNCHER" />
        </intent-filter>
</activity>

```
## 5 AndroidMainfest配置（母包）
```xml
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="你的包名"
    android:versionCode="1"
    android:versionName="1.0" >

    <uses-sdk
        android:minSdkVersion="8"
        android:targetSdkVersion="24" />

       
	 <!--  如果工程不存在Application   必须这样写android:name="com.ztgame.ztgameframework.ZTApplication"   -->

	 <!--  如果工程 存在Application   必须继承ZTApplication 并且在 onCreate() 函数中添加 super.onCreate(),

	     android:name="游戏包名.游戏的application"  

		 -->	 	

	 <!--  android:launchMode 设置成 standard 或者 singleTop	 -->
     <application
	    android:name="参考以上写法"
        android:allowBackup="true"
        android:icon="@drawable/ic_launcher"
        android:label="@string/app_name"
        android:theme="@style/AppTheme" >
    </application>
    <!--  
	 所有的activity service等标签 android:name 字段写上对应的java包名的全称(全路径)
	 activity 中包含 android:configChanges="orientation|keyboardHidden|screenSize"
	-->
	<!-- 例如 <activity android:name="你的包名.xxxxxActivity"
            android:configChanges="orientation|keyboardHidden|screenSize"/>   
		<-->
</manifest>

```

