(function ($$) {

        "use strict";


        $$(function () {

		$$.PAGE_WAITING_DIV ="<div id=\"page_waiting\" class=\"running\"></div><div class=\"page_doing running\"> \
                          <div class=\"loadingMessage roundCorners\">请等待一会...</div></div>"

		$$.submit_wait = function(container, string) {
                        $$(container).append(string);
                };
		/**
                 * @function post form data.
                 * @param {container id or class} - the id or class of the container
                 * @param {url} - request url, if it's NULL or empty, it will auto get formId's action value.
                 * @param {function} - callback function
                 */
                $$.postForm = function (container, url, callback) {
			url = $$(container).attr("action");
                        var funcs = function(json) {
                                if ( callback != null )
                                        callback(json);
                        };

                        $$.ajax({
                                url: url,
                                type: "POST",
                                data: $$(container).serialize(),
                                dataType: 'json',
                                contentType: "application/json; charset=utf-8",
                                success: funcs
                        });
		};

		$$.getData = function (url, callback, ajax_error) {
			var new_url = url;

			$$.ajax({
				url: new_url,
				success: function(json) {
					callback(json);
				},
				dataType: "json",
				error: function(){
					ajax_error();
				}
			});
		};

	// regular expression
	$$.REG_PASSWORD = /^[0-9a-zA-Z]{6,32}$/;
	$$.REG_NUM = /^([\x30-\x39]){1,6}$/;
	$$.REG_PHONE = /^([\x30-\x39]|[\x2B]){1,20}$/;;

	if ( $$('#loginForm').length ) {
		var count = 0;
		if(funjsq_no_need_login == "1")
			location.href="funjsq_select.htm";

		if(forget_or_register == "1"){
			$$('#forgetBt').trigger('click');
		}else if(forget_or_register == "2"){
			$$('#registerBt').trigger('click');
		}

		$$('#loginBt').click(function() {
			var cf=document.forms[0];
			if ( !$$.REG_PHONE.test($$('#loginName').val()) ) {
                                alert("无效的账号！");
                                return false;
                        }else{
                                cf.hidden_funjsq_username.value = cf.funjsq_username.value;
                        }

			if ( !$$.REG_PASSWORD.test($$('#loginPwd').val()) ) {
				alert("无效的密码！");
				return false;
			}else{
				cf.hidden_funjsq_password.value = cf.funjsq_password.value;
                        }

			cf.action="/admin.cgi?/funjsq_login.htm timestamp="+ts;
			$$('#loginForm').css('display','none');
			$$('.plz_wait').css('display','block');
			$$('body').css('background','white');
			$$.postForm('#loginForm', '', function(json) {
				if ( json.status == "success" && json.code =="1000") {
                                        location.href = "funjsq_select.htm";
                                } else if ( json.code !="1000"){
					$$('#loginForm').css('display','block');
					$$('.plz_wait').css('display','none');
					$$('body').css('background','rgb(229,229,229)');
					if( json.code == "1001"){
						alert("该号码尚未注册完成，请确认输入是否正确");
					}else if( json.code == "1002" || json.code == "1003"){
						count++;
						if(count < 3){
							if( json.code == "1002" )
								alert("手机号码输入错误，请确认输入是否正确");
							else
								alert("密码输入错误，请确认输入是否正确");
                                                }else {
                                                        count=0;
                                                        alert("您已重复输入错误的账号或密码3次，请您提供电话号码，以便我们提供验证码做确认");
							$$('#forgetBt').trigger("click");
                                                }
					}
                                        //location.href = "funjsq_login.htm";
                                } else{
					$$('#loginForm').css('display','block');
                                        $$('.plz_wait').css('display','none');
					$$('body').css('background','rgb(229,229,229)');
                                        alert("请检查你的网络连接。");
                                        //location.href = "funjsq_login.htm";
                                }
			});
		});

		$$('#forgetBt').click(function() {
			$$('#loginForm').css('display','none');
			$$('#registerForm').css('display','none');
			$$('#forgetForm').css('display','block');
		});

		$$('#registerBt').click(function() {
			if(!confirm("新会员注册成功后，您将获得24小时的免费使用权。为确保您充分体验该服务，建议您在开始游戏前再注册账号"))
				return false;

			$$('#loginForm').css('display','none');
			$$('#registerForm').css('display','block');
			$$('#forgetForm').css('display','none');
		});

		$$('#forgetBackBt').click(function() {
                        $$('#loginForm').css('display','block');
                        $$('#registerForm').css('display','none');
                        $$('#forgetForm').css('display','none');
                });

		$$('#registerBackBt').click(function() {
                        $$('#loginForm').css('display','block');
                        $$('#registerForm').css('display','none');
                        $$('#forgetForm').css('display','none');
                });

		var wait=60;
		$$.time_count = function(form) {
                        if(wait == 0){
                                $$('#'+form+'VerifyBt').prop('disabled',false);
                                wait = 60;
                                $$('#'+form+'VerifyBt').val("获取验证码");
				$$('#'+form+'VerifyBt').removeClass("disabled");
                        }else{
                                $$('#'+form+'VerifyBt').prop('disabled',true);
                                $$('#'+form+'VerifyBt').val("重新发送("+wait+"s)");
				$$('#'+form+'VerifyBt').addClass("disabled");
                                wait--;
				setTimeout(function(){
					$$.time_count(form);
				},1000);
                        }
		}

		$$.get_verify = function (num,form)
		{
			var cf=document.forms[num];
			if ( !$$.REG_PHONE.test($$('#'+form+'Name').val()) ) {
                                alert("无效的账号！");
                                return false;
                        }else{
                                cf.hidden_funjsq_username.value = cf.funjsq_username.value;
                        }

			cf.submit_flag.value=""+form+"_get_verify";
			cf.action="/admin.cgi?/funjsq_login.htm timestamp="+ts;
			wait=60;
			$$.time_count(form);
			$$.postForm('#'+form+'Form', '', function(json) {	
				if ( json.code == "1000" ) {
					return true;
				} else if ( json.status == "error"){
					if( json.code == "1001"){
						if( form == "register")
							alert("该手机号码已注册，请确认");
						else
							alert("该号码尚未注册完成，请确认输入是否正确");
					}else if( json.code == "1002"){
						alert("手机号码输入错误，请确认输入是否正确");
					}else if( json.code == "1003"){
                                                alert("验证码调用次数过多，请一天后重试");
					}
					wait=0;
				} else{
					alert("请检查你的网络连接。");
					wait=0;
				}
			});
		}

		var verify_count = 0;
		$$.forget_register_apply = function (num,form)
		{
			var cf=document.forms[num];
			if ( !$$.REG_PHONE.test($$('#'+form+'Name').val()) ) {
                                alert("无效的账号！");
                                return false;
                        }else{
                                cf.hidden_funjsq_username.value = cf.funjsq_username.value;
                        }
			if ( !$$.REG_PASSWORD.test($$('#'+form+'Pwd').val()) ) {
                                alert("无效的密码！");
                                return false;
                        }else{
                                cf.hidden_funjsq_password.value = cf.funjsq_password.value;
                        }

			if ( !$$.REG_NUM.test($$('#'+form+'Vry').val()) ) {
                                alert("无效的验证码！");
                                return false;
                        }else{
                                cf.hidden_funjsq_verify.value = cf.funjsq_verify.value;
                        }

			cf.hidden_funjsq_verify.value = cf.funjsq_verify.value;
			cf.action="/admin.cgi?/funjsq_login.htm timestamp="+ts;
			cf.submit_flag.value="funjsq_"+form+"";
			$$('.plz_wait').css('display','block');
			$$('#'+form+'Form').css('display','none');
			$$('body').css('background','white');
			$$.postForm('#'+form+'Form', '', function(json) {
				if ( json.code == "1000" ) {
					cf.submit_flag.value="funjsq_login";
					$$.postForm('#'+form+'Form', '', function(json) {
						if ( json.status == "success" && json.code =="1000") {
							location.href = "funjsq_select.htm";
						}else{
							$$('.plz_wait').css('display','none');
							$$('#loginForm').css('display','block');
							$$('body').css('background','rgb(229,229,229)');
							alert("请重新登陆");
						}
					});
				}else{
					$$('.plz_wait').css('display','none');
					$$('body').css('background','rgb(229,229,229)');
					$$('#'+form+'Form').css('display','block');
					if ( json.code == "1002" ) {
						alert("手机号码输入错误，请确人输入是否正确");
					}else if ( json.code == "5001" ) {
						alert("验证码未输入，请确认");
					}else if ( json.code == "5002" || json.code == "5003") {
						if( form == "forget"){
                                                        verify_count++;
                                                        if(verify_count < 3){
								if( json.code == "5003" )
                                                                        alert("验证码输入错误，请重新输入验证码");
								else
									alert("验证码已失效，请重新获取验证码");
                                                        }else{
                                                                alert("验证码输入错误，请联系客服");
                                                        }
                                                }else{
							if( json.code == "5003" )
								alert("验证码输入错误，请重新输入验证码");
							else
								alert("验证码已失效，请重新获取验证码");
                                                }
					}
					if(form == "register"){
						if ( json.code == "1001" ) {
							alert("该手机号码已注册，请确认");
						}else if ( json.code == "1003" ) {
							alert("验证码调用次数过多，请一天后重试");
						}
					}else if(form == "forget"){
						if ( json.code == "1001" ) {
                                                        alert("该号码尚未注册完成，请确认输入是否正确");
                                                }
					}
				}
			});
		}
	}

	if ( $$('#loginNewForm').length ) {
                var count = 0;
                if(funjsq_no_need_login == "1")
                        location.href="funjsq_select_new.htm";

                if(forget_or_register == "1"){
                        $$('#forgetBt').trigger('click');
                }else if(forget_or_register == "2"){
                        $$('#registerBt').trigger('click');
                }

		$$('#loginBt').click(function() {
                        var cf=document.forms[0];
                        if ( !$$.REG_PHONE.test($$('#loginName').val()) ) {
                                alert("无效的账号！");
                                return false;
                        }else{
                                cf.hidden_funjsq_username.value = cf.funjsq_username.value;
                        }

                        if ( !$$.REG_PASSWORD.test($$('#loginPwd').val()) ) {
                                alert("无效的密码！");
                                return false;
                        }else{
                                cf.hidden_funjsq_password.value = cf.funjsq_password.value;
                        }

			cf.action="/admin.cgi?/funjsq_login_new.htm timestamp="+ts;
                        $$('#loginNewForm').css('display','none');
                        $$('.plz_wait').css('display','block');
                        $$('body').css('background','white');
			$$.postForm('#loginNewForm', '', function(json) {
                                if ( json.status == "success" && json.code =="1200") {
                                        location.href = "funjsq_select_new.htm";
                                } else if ( json.code !="1200"){
                                        $$('#loginNewForm').css('display','block');
                                        $$('.plz_wait').css('display','none');
                                        $$('body').css('background','rgb(229,229,229)');
                                        if( json.code == "1201"){
                                                alert("该号码尚未注册完成，请确认输入是否正确");
					}else if( json.code == "1202" || json.code == "1203"){
                                                count++;
                                                if(count < 3){
                                                        if( json.code == "1202" )
                                                                alert("手机号码输入错误，请确认输入是否正确");
                                                        else
                                                                alert("密码输入错误，请确认输入是否正确");
                                                }else {
                                                        count=0;
                                                        alert("您已重复输入错误的账号或密码3次，请您提供电话号码，以便我们提供验证码做确认");
                                                        $$('#forgetBt').trigger("click");
                                                }
                                        }
                                        //location.href = "funjsq_login.htm";
                                } else{
					$$('#loginNewForm').css('display','block');
                                        $$('.plz_wait').css('display','none');
                                        $$('body').css('background','rgb(229,229,229)');
                                        alert("请检查你的网络连接。");
                                        //location.href = "funjsq_login.htm";
                                }
                        });
                });

		$$('#forgetBt').click(function() {
                        $$('#loginNewForm').css('display','none');
                        $$('#registerNewForm').css('display','none');
                        $$('#forgetNewForm').css('display','block');
                });

                $$('#registerBt').click(function() {
                        if(!confirm("新会员注册成功后，您将获得24小时的免费使用权。为确保您充分体验该服务，建议您在开始游戏前再注册账号"))
                                return false;

                        $$('#loginNewForm').css('display','none');
                        $$('#registerNewForm').css('display','block');
                        $$('#forgetNewForm').css('display','none');
                });

                $$('#forgetBackBt').click(function() {
                        $$('#loginNewForm').css('display','block');
                        $$('#registerNewForm').css('display','none');
                        $$('#forgetNewForm').css('display','none');
                });

                $$('#registerBackBt').click(function() {
                        $$('#loginNewForm').css('display','block');
                        $$('#registerNewForm').css('display','none');
                        $$('#forgetNewForm').css('display','none');
                });

		var wait=60;
                $$.time_count = function(form) {
                        if(wait == 0){
                                $$('#'+form+'VerifyBt').prop('disabled',false);
                                wait = 60;
                                $$('#'+form+'VerifyBt').val("获取验证码");
                                $$('#'+form+'VerifyBt').removeClass("disabled");
                        }else{
                                $$('#'+form+'VerifyBt').prop('disabled',true);
                                $$('#'+form+'VerifyBt').val("重新发送("+wait+"s)");
                                $$('#'+form+'VerifyBt').addClass("disabled");
                                wait--;
                                setTimeout(function(){
                                        $$.time_count(form);
                                },1000);
                        }
                }

		$$.get_verify = function (num,form)
                {
                        var cf=document.forms[num];
                        if ( !$$.REG_PHONE.test($$('#'+form+'Name').val()) ) {
                                alert("无效的账号！");
                                return false;
                        }else{
                                cf.hidden_funjsq_username.value = cf.funjsq_username.value;
                        }

                        cf.submit_flag.value=""+form+"_get_verify";
                        cf.action="/admin.cgi?/funjsq_login_new.htm timestamp="+ts;
                        wait=60;
			$$.time_count(form);
                        $$.postForm('#'+form+'NewForm', '', function(json) {
                                if ( json.code == "1100" || json.code == "1300" ) {
                                        return true;
                                } else if ( json.status == "error"){
                                        if( json.code == "1101"){
                                                alert("该手机号码已注册，请确认");
					}else if( json.code == "1301"){
                                                alert("该号码尚未注册完成，请确认输入是否正确");
                                        }else if( json.code == "1102" || json.code == "1302"){
                                                alert("手机号码输入错误，请确认输入是否正确");
                                        }else if( json.code == "1103" || json.code == "1303"){
                                                alert("验证码调用次数过多，请一天后重试");
                                        }
                                        wait=0;
                                } else{
                                        alert("请检查你的网络连接。");
                                        wait=0;
                                }
                        });
                }

		var verify_count = 0;
                $$.forget_register_apply = function (num,form)
                {
                        var cf=document.forms[num];
                        if ( !$$.REG_PHONE.test($$('#'+form+'Name').val()) ) {
                                alert("无效的账号！");
                                return false;
                        }else{
                                cf.hidden_funjsq_username.value = cf.funjsq_username.value;
                        }
                        if ( !$$.REG_PASSWORD.test($$('#'+form+'Pwd').val()) ) {
                                alert("无效的密码！");
                                return false;
                        }else{
                                cf.hidden_funjsq_password.value = cf.funjsq_password.value;
                        }

			if ( !$$.REG_NUM.test($$('#'+form+'Vry').val()) ) {
                                alert("无效的验证码！");
                                return false;
                        }else{
                                cf.hidden_funjsq_verify.value = cf.funjsq_verify.value;
                        }

                        cf.hidden_funjsq_verify.value = cf.funjsq_verify.value;
                        cf.action="/admin.cgi?/funjsq_login_new.htm timestamp="+ts;
                        cf.submit_flag.value="funjsq_"+form+"";
                        $$('.plz_wait').css('display','block');
                        $$('#'+form+'Form').css('display','none');
                        $$('body').css('background','white');
			$$.postForm('#'+form+'NewForm', '', function(json) {
                                if ( json.code == "1104" || json.code == "1304" ) {
                                        cf.submit_flag.value="funjsq_login";
                                        $$.postForm('#'+form+'NewForm', '', function(json) {
                                                if ( json.status == "success" && json.code =="1000") {
                                                        location.href = "funjsq_select_new.htm";
                                                }else{
                                                        $$('.plz_wait').css('display','none');
                                                        $$('#loginForm').css('display','block');
                                                        $$('body').css('background','rgb(229,229,229)');
                                                        alert("请重新登陆");
                                                }
                                        });
				}else{
                                        $$('.plz_wait').css('display','none');
                                        $$('body').css('background','rgb(229,229,229)');
                                        $$('#'+form+'Form').css('display','block');
                                        if ( json.code == "1106" || json.code == "1306") {
                                                alert("手机号码输入错误，请确人输入是否正确");
                                        }else if ( json.code == "1107" || json.code == "1307") {
                                                alert("验证码未输入，请确认");
                                        }else if ( json.code == "1108" || json.code == "1109" || json.code == "1308" || json.code == "1309" || json.code == "1103") {
                                                if( form == "forget"){
                                                        verify_count++;
                                                        if(verify_count < 3){
                                                                if( json.code == "1303" )

 alert("验证码输入错误，请重新输入验证码");
                                                                else
                                                                        alert("验证码已失效，请重新获取验证码");
                                                        }else{
                                                                alert("验证码输入错误，请联系客服");
                                                        }
                                                }else{
							if( json.code == "1109" || json.code == "1309")
                                                                alert("验证码输入错误，请重新输入验证码");
                                                        else
                                                                alert("验证码已失效，请重新获取验证码");
                                                }
                                        }
                                        if(form == "register"){
                                                if ( json.code == "1105" ) {
                                                        alert("该手机号码已注册，请确认");
                                                }
                                        }else if(form == "forget"){
                                                if ( json.code == "1305" ) {
                                                        alert("该号码尚未注册完成，请确认输入是否正确");
                                                }
                                        }
                                }
                        });
                }
        }

	if ( $$('#selectForm').length ) {
		var progress=0;

		function is_win_req(){
			var system = {};
			var p = navigator.platform;
			system.win = p.indexOf("Win")==0;
			if(system.win){
				return true;
			}else{
				return false;
			}
		}
		var windowAjaxCount = 1;
		$$.getPluginInfo = function() {
                        $$.getData('plugin_info.aspx',function(json){
                                if(json.funjsq_status == "1"){
                                        progress=0;
                                        $$('#funjsq_icon2').removeClass("icon_fail");
                                        $$('#funjsq_icon2').removeClass("icon_start");
                                        $$('#funjsq_icon2').removeClass("icon_access");
                                        $$('#funjsq_icon2').addClass("icon_success");
                                        $$('.circleProgress_wrapper').css('display','none');
                                        $$('#status_info').html("加速成功");
					$$('#status_info2').html("");
                                        $$('#funjsqConntime').html(json.funjsq_conntime);
                                        $$('#funjsqIp').html(json.funjsq_ip);
                                        $$('#funjsqMac').html(json.funjsq_mac);
                                        $$('#funjsqTXbyte').html(json.funjsq_TXbyte);
                                        $$('#funjsqRXbyte').html(json.funjsq_RXbyte);
                                        setTimeout(function(){$$.getPluginInfo();},1*1000);
				}else if (json.funjsq_status == "2"){
                                        progress=0;
                                        $$('#funjsq_icon2').removeClass("icon_fail");
                                        $$('#funjsq_icon2').removeClass("icon_start");
                                        $$('#funjsq_icon2').removeClass("icon_success");
                                        $$('#funjsq_icon2').addClass("icon_access");
                                        $$('.circleProgress_wrapper').css('display','none');
                                        $$('#funjsqConntime').html(json.funjsq_conntime);
                                        $$('#funjsqIp').html(json.funjsq_ip);
                                        $$('#funjsqMac').html(json.funjsq_mac);
                                        $$('#funjsqTXbyte').html(json.funjsq_TXbyte);
                                        $$('#funjsqRXbyte').html(json.funjsq_RXbyte);
					if( json.funjsq_accType == "2"){
						$$.detectWin = function() {
							$$.ajax({
                                                                type:'get',
                                                                url:"https://www"+windowAjaxCount+".playstation.net",
                                                                success:function(){},
                                                                error:function() {}
                                                        });
							windowAjaxCount++;
						};
						$$.detectWin();
						setTimeout(function(){$$.getPluginInfo();},3*1000);
					}else{
						setTimeout(function(){$$.getPluginInfo();},1*1000);
					}
					if( json.funjsq_accType == "1"){
                                                $$('#status_info').html("请在PS4中操作：[设定]-[网络]-[测试网络连线]");
                                                $$('#status_info2').html("如果测速失败，请尝试多测速几次");
                                        }
                                        else if ( json.funjsq_accType == "3"){
                                                $$('#status_info').html("请在Xbox中操作：[设置]-[网络设置]-[检查网络连线]");
                                                $$('#status_info2').html("如果测速失败，请尝试多测速几次");
                                        }
					else if ( json.funjsq_accType == "4"){
						$$('#status_info').html("请在Nintendo Switch中操作：[设置]-[网络设置]-[检查网络连线]");
                                                $$('#status_info2').html("如果测速失败，请尝试多测速几次");
					}
                                        else {
                                                $$('#status_info').html("请确保您的电脑与本路由器在同一网络");
                                        }
				}else if (json.funjsq_status == "7"){
                                        $$('#status_info').html("开启中");
					$$('#status_info2').html("");
                                        $$('#funjsq_icon2').removeClass("icon_fail");
                                        $$('#funjsq_icon2').removeClass("icon_success");
                                        $$('#funjsq_icon2').removeClass("icon_access");
                                        $$('.circleProgress_wrapper').css('display','block');
                                        $$.progress_bar();
                                        setTimeout(function(){$$.getPluginInfo();},3*1000);
                                }else if (json.funjsq_status == "0"){
                                        progress=0;
					$$('#funjsqConntime').html(json.funjsq_conntime);
                                        $$('#funjsqIp').html(json.funjsq_ip);
                                        $$('#funjsqMac').html(json.funjsq_mac);
                                        $$('#funjsqTXbyte').html(json.funjsq_TXbyte);
                                        $$('#funjsqRXbyte').html(json.funjsq_RXbyte);
                                        $$('#status_info').html("服务器未启动");
					$$('#status_info2').html("");
                                        $$('#funjsq_icon2').addClass("icon_fail");
                                        $$('#funjsq_icon2').removeClass("icon_start");
                                        $$('#funjsq_icon2').removeClass("icon_access");
                                        $$('#funjsq_icon2').removeClass("icon_success");
                                        $$('.circleProgress_wrapper').css('display','none');
                                        //setTimeout(function(){$$.getPluginInfo();},3*1000);
				}else if (json.funjsq_status == "5"){
					progress=0;
					alert("密码发生变动，请重新登陆账号");
					var cf=document.forms[0];
					cf.submit_flag.value = "need_login";
					cf.action="/admin.cgi?/funjsq_select.htm timestamp="+ts;
					$$.postForm('#selectForm', '', function(json) {
                                                        if ( json.status == "1" ) {
                                                                location.href = "funjsq_login.htm";
							} else {
								alert("请重试");
							}
					});
				}else {
                                        progress=0;
                                        $$('#funjsq_icon2').addClass("icon_fail");
                                        $$('#funjsq_icon2').removeClass("icon_start");
                                        $$('#funjsq_icon2').removeClass("icon_access");
                                        $$('#funjsq_icon2').removeClass("icon_success");
                                        $$('.circleProgress_wrapper').css('display','none');
					$$('#pluginBt').val("开启服务");
					$$('#status_info2').html("");
                                        if (json.funjsq_status == "3"){
                                                $$('#status_info').html("会员过期，请续费");
                                        }
                                        else if (json.funjsq_status == "6"){
                                                $$('#status_info').html("服务器启动失败，请检查网络状况");
                                                $$('#status_info2').html("请尝试更改路由器的DNS为233.5.5.5或者114.114.114.114");
                                        }
                                        else if (json.funjsq_status == "8"){
                                                $$('#status_info').html("操作异常，请重新开启插件");
                                        }
                                        else if (json.funjsq_status == "9"){
                                                $$('#status_info').html("后台插件升级成功，请重新开启插件");
                                        }
					else if (json.funjsq_status == "10"){
                                                $$('#status_info').html("网络抖动，服务已断线，请重新开启服务");
                                        }
                                }
                        });
		}

		$$('#accType').val(accType);
		$$('#funjsqConntime').html(funjsq_conntime);
		$$('#funjsqIp').html(funjsq_ip);
		$$('#funjsqMac').html(funjsq_mac);
		$$('#funjsqTXbyte').html(funjsq_TXbyte);
                $$('#funjsqRXbyte').html(funjsq_RXbyte);
		if(funjsq_status != "0"){
			$$.getPluginInfo();
			$$('#pluginBt').val("关闭服务");
		}

		$$.getData('https://api.funjsq.com/thirdParty/netgear/AccNode.php',function(json){
			var newRow = "";
			for(var key in json){
				newRow = '<option';
				newRow += ' value="'+key+'">'+json[key]+'</option>';
				$$('#accArea').append(newRow);
			}
			$$('#accArea').val(accArea);
		},function(){
			var newRow = "";
			newRow ='<option value="AUTO">自动（推荐）</option><option value="HK">香港</option><option value="JP">日本</option>';
			$$('#accArea').append(newRow);
			$$('#accArea').val(accArea);
		});

		$$('#pluginBt').click(function() {
			var cf=document.forms[0];

			if($$('#accType').val() == "0")
			{
				alert("请选择加速类型！");
				return false;
			}

			if ($$('#accType').val() == "2"){
				if(is_win_req() == false){
					alert("请使用Window PC访问");
					return false;
				}
			}

			if($$('#accArea').val() == "0")
                        {
                                alert("请选择加速节点！");
                                return false;
                        }

			cf.hidden_accType.value = cf.accType.value;
			cf.hidden_accArea.value = cf.accArea.value;
			if($$('#pluginBt').val() =="开启服务")
			{
				$$('#pluginBt').val("关闭服务");
				cf.submit_flag.value="open_plugin";
			}else if ($$('#pluginBt').val() =="关闭服务")
			{
				$$('#pluginBt').val("开启服务");
				cf.submit_flag.value="close_plugin";
			}

			cf.action="/admin.cgi?/funjsq_select.htm timestamp="+ts;
			$$.postForm('#selectForm', '', function(json) {
				if(cf.submit_flag.value =="open_plugin"){
					progress=0;
					if ( json.status == "1" ) {
						$$.getPluginInfo();
						//location.href = "funjsq_select.htm";
					} else {
						//location.href = "funjsq_pay.htm";
						alert("请重试");
					}
				}else{
					if ( json.status == "1" ) {
						$$.checkStatus();
						//location.href = "funjsq_select.htm";
					} else {
						alert("无效的请求，请重试");
						//location.href = "funjsq_select.htm";
					}
				}
			});
			return true;
		});

		$$('#resetBt').click(function() {
			var cf=document.forms[0];
			cf.submit_flag.value="reset_plugin";
			cf.action="/admin.cgi?/funjsq_select.htm timestamp="+ts;
			$$.postForm('#selectForm', '', function(json) {
				if ( json.status == "1" ) {
					$$.checkStatus();
					location.href = "funjsq_select.htm";
				} else {
					alert("无效的请求，请重试");
					//location.href = "funjsq_select.htm";
				}
			});
			return true;
		});

		var last_select = accType;
		$$('#accType').change(function() {
			var cf=document.forms[0];

                        if($$('#accType').val() == "0")
                                return true;

			if($$('#accType').val() != "2")
				last_select = cf.accType.value;

			if(is_win_req() == false && $$('#accType').val() == "2"){
				alert("请使用Window PC访问");
				$$('#accType').val(last_select);
				return false;
			}

                        cf.hidden_accType.value = cf.accType.value;
			cf.hidden_accArea.value = cf.accArea.value;
			$$.getData('plugin_info.aspx',function(json){
				if (json.funjsq_status == "1" || json.funjsq_status == "2")
				{
					progress=0;
					$$('#pluginBt').val("关闭服务");
					if (json.funjsq_ip == "x.x.x.x"){
						cf.submit_flag.value ="open_plugin";
						cf.action="/admin.cgi?/funjsq_select.htm timestamp="+ts;
						$$.postForm('#selectForm', '', function(json) {
							if ( json.status == "1" ) {
								//getPluginInfo();
								return true;
							} else {
								alert("请检查你的网络连接。");
								//location.href = "funjsq_select.htm";
							}
						});
					}else{
						cf.submit_flag.value ="open_plugin";
						cf.action="/admin.cgi?/funjsq_select.htm timestamp="+ts;
                                                $$.postForm('#selectForm', '', function(json) {
                                                        if ( json.status == "1" ) {
                                                                //getPluginInfo();
								//setTimeout(function(){$$.getPluginInfo();},3000);
								return true;
                                                        } else {
								alert("请检查你的网络连接。");
                                                                //location.href = "funjsq_select.htm";
                                                        }
                                                });
					}
				}
			});
		});

		$$('#accArea').change(function() {
			$$('#accType').trigger("change");
		});

		$$.progress_bar = function() {
			if(progress == 90){
				$$('.progress').html("90%");
				setTimeout(function(){
					$$('.circleProgress_wrapper').css('display','none');
					$$('#funjsq_icon2').addClass("icon_fail");
				},1500);
				$$('#resetBt').trigger("click");
				$$('#pluginBt').val("开启服务");
			}else{
				$$('.progress').html(""+progress+"%");
				progress = parseInt(progress)+10;
			}
		}
		$$('#accArea').val(accArea);

	}

	if ( $$('#selectNewForm').length ) {
		var devNum = "0";
		var progress=0;
		$$.getData('mul_device.aspx',function(json){
                        var newRow = "";
			var num=0;
			var connect_status="funjsq_disable2",connect_value,font_value,font_color="gray";
			var Area = new Array();
                        for(var key in json){
				if(key == "deviceNum"){
					devNum = json.deviceNum;
				}else if ( devNum != "0"){
					Area[num]=json[key].accArea;
					$$('.funjsq_no_device').css('display','none');	
					newRow = '<table class="funjsq_mul_device" cellspacing="3" cellpadding="0"><tr>';
					if(json[key].type == "1"){
						newRow += '<td rowspan="2" class="icon_play"></td>';
					}else if (json[key].type == "2"){
						newRow += '<td rowspan="2" class="icon_windows"></td>';
					}else if (json[key].type == "3"){
						newRow += '<td rowspan="2" class="icon_xbox"></td>';
					}else if (json[key].type == "4"){
						newRow += '<td rowspan="2" class="icon_nint"></td>';
					}else {
						newRow += '<td rowspan="2" class="icon_unknow"></td>';
					}
					if(json[key].status == "1"){
						connect_status = "funjsq_enable2";
						connect_value = "open";
						font_color = "green";
						font_value = "加速成功";
					}else if (json[key].status == "6"){
						connect_status = "funjsq_disable2";
						connect_value = "close";
						font_color = "red";
						font_value = "开启失败";
					}else if (json[key].status == "8"){
						connect_status = "funjsq_disable2";
						connect_value = "close";
						font_color = "red";
						font_value = "操作异常";
					}else if (json[key].status == "10"){
						connect_status = "funjsq_disable2";
						connect_value = "close";
						font_color = "gray";
						font_value = "已断线";
					}else {
						connect_status = "funjsq_disable2";
						font_color = "gray";
						connect_value = "close";
						font_value = "联机加速";
					}
					newRow += '<td id="mulMac'+num+'">MAC:'+key+'</td><td id="mulTxb'+num+'">上传流量: '+json[key].TXbyte+'</td><td>请选择加速节点</td><td class="icon_update_shop '+connect_status+'" id="plugin'+num+'" onclick="$$.pluginClick('+num+', '+json[key].type+');" style="width:13%;"><input hidden="" value="'+connect_value+'" id="pluginBt'+num+'"><div class="circleProgress_wrapper_new" id="circle'+num+'" hidden=""><div class="progress_new" id="progress'+num+'"></div><div class="wrapper_new right_new"><div class="circleProgress_new rightcircle_new"></div></div><div class="wrapper_new left_new"><div class="circleProgress_new leftcircle_new"></div></div></div></td></tr><tr><td>';
					newRow += 'IP:'+json[key].IP+'</td><td id="mulRxb'+num+'">下载流量: '+json[key].RXbyte+'</td><td><select id="accArea'+num+'" name="accArea" onChange="$$.accAreaChange('+num+');"><option value="0" selected>请选择加速节点</option></select></td><td style="color:'+font_color+';" id="fontStatus'+num+'">'+font_value+'</td></tr></table>';
					$$('.funjsq_type_new').append(newRow);
					num++;
				}
			}

			$$.getData('https://api.funjsq.com/thirdParty/netgear/AccNode.php',function(json){
                                var areaRow = "";
                                var i;
                                for(var key in json){
                                        areaRow = '<option';
                                        areaRow += ' value="'+key+'">'+json[key]+'</option>';

                                        for( i=0; i<devNum; i++){
                                                $$('#accArea'+i+'').append(areaRow);
						$$('#accArea'+i+'').val(Area[i]);
                                        }
                                }
                        },function(){
                                var areaRow = "";
                                var i;
                                areaRow ='<option value="AUTO">自动（推荐）</option><option value="HK">香港</option><option value="JP">日本</option>';
                                for(i=0; i<devNum; i++){
                                        $$('#accArea'+i+'').append(areaRow);
                                        $$('#accArea'+i+'').val(accArea);
                                }

                        });
                },function(){
                });

		$$.accAreaChange = function(count) {
			$$.getData('mul_device.aspx',function(json){
				var num=0;
				for(var key in json){
					if(count == num){
						if( json[key].status == "1" ){
							var cf = document.forms[0];

							cf.selMac.value = key;
							cf.selType.value = json[key].type;
							cf.selArea.value = $$('#accArea'+num+'').val();
							cf.action="/admin.cgi?/funjsq_select_new.htm timestamp="+ts;
							cf.submit_flag.value ="open_plugin_new";
							$$.postForm('#selectNewForm', '', function(json) {
								progress=0;
								if ( json.status == "1") {
									$$.updateStatus(key);
								} else {
									alert("请重试");
								}
							});
						}
					}

					if( key != "deviceNum" )
                                                num++;
				}
			});
		}

		$$.updateStatus = function(select_mac) {
			$$.getData('refresh_status.aspx',function(json){
			    if(json.refresh_status == "1"){
                            $$.getData('mul_device.aspx',function(json){
				var num=0;
				for(var key in json){
					if(key == select_mac){
						if( json[key].status == "1" ){
							progress=0;
							$$('#pluginBt'+num+'').val("open");
							$$('#plugin'+num+'').removeClass("funjsq_disable2");
							$$('#plugin'+num+'').addClass("funjsq_enable2");
							$$('#plugin'+num+'').removeClass("active");
							$$('#circle'+num+'').css('display','none');
							$$('#mulTxb'+num+'').html('上传流量: '+json[key].TXbyte+'');
							$$('#mulRxb'+num+'').html('下载流量: '+json[key].RXbyte+'');
							$$('#fontStatus'+num+'').html("加速成功");
							$$('#fontStatus'+num+'').css('color','green');
							setTimeout(function(){$$.updateStatus(select_mac);},1*1000);
						}else if( json[key].status == "7" ){
							$$('#pluginBt'+num+'').val("wait");
                                                        $$('#plugin'+num+'').removeClass("funjsq_disable2");
							$$('#plugin'+num+'').removeClass("funjsq_enable2");
							$$('#plugin'+num+'').addClass("active");
							$$('#circle'+num+'').css('display','block');
							$$('#fontStatus'+num+'').html("开启中");
							$$('#fontStatus'+num+'').css('color','gray');
							$$.progress_bar(num);
							setTimeout(function(){$$.updateStatus(select_mac);},3*1000);
						}else{
							progress=0;
							$$('#pluginBt'+num+'').val("close");
                                                        $$('#plugin'+num+'').removeClass("funjsq_enable2");
                                                        $$('#plugin'+num+'').addClass("funjsq_disable2");
							$$('#plugin'+num+'').removeClass("active");
							$$('#circle'+num+'').css('display','none');
							if( json[key].status == "6" ){
								$$('#fontStatus'+num+'').html("开启失败");
								$$('#fontStatus'+num+'').css('color','red');
							}else if( json[key].status == "10" ){
								$$('#fontStatus'+num+'').html("已断线");
								$$('#fontStatus'+num+'').css('color','gray');
							}else if( json[key].status == "8" ){
                                                                $$('#fontStatus'+num+'').html("操作异常");
                                                                $$('#fontStatus'+num+'').css('color','red');
							}else if ( json[key].status == "0" ){
								$$('#fontStatus'+num+'').html("联机加速");
                                                                $$('#fontStatus'+num+'').css('color','gray');
							}
						}
					}

					if( key != "deviceNum" )
                                                num++;
				}
                            },function(){
                            });
			    }
			},function(){
			});
		}

		$$.pluginClick = function(num, type) {
			var cf=document.forms[0];

			for(var i=0;i < devNum;i++){
				if(i != num && $$('#plugin'+i+'').hasClass("active"))
				{
					alert("请等待另一台设备加速完成！");
					return false;
				}
			}

			if($$('#accArea'+num+'').val() == "0")
                        {
                                alert("请选择加速节点！");
                                return false;
                        }

			if($$('#pluginBt'+num+'').val() =="open")
                        {
                                $$('#pluginBt'+num+'').val("close");
				$$('#plugin'+num+'').removeClass("funjsq_enable2");
				$$('#plugin'+num+'').addClass("funjsq_disable2");
                                cf.submit_flag.value="close_plugin_new";
                        }else if ($$('#pluginBt'+num+'').val() =="close")
                        {
                                $$('#pluginBt'+num+'').val("open");
				$$('#plugin'+num+'').removeClass("funjsq_disable2");
                                $$('#plugin'+num+'').addClass("funjsq_enable2");
                                cf.submit_flag.value="open_plugin_new";
                        }

			var select_mac = $$('#mulMac'+num+'').html().substring(4,21);
			cf.selMac.value = select_mac;
			cf.selType.value = type;
			cf.selArea.value = $$('#accArea'+num+'').val();
			cf.action="/admin.cgi?/funjsq_select.htm timestamp="+ts;
			$$.postForm('#selectNewForm', '', function(json) {
				if(cf.submit_flag.value =="open_plugin_new"){
                                        progress=0;
                                        if ( json.status == "1" ) {
						$$('#pluginBt'+num+'').val("wait");
                                                $$('#plugin'+num+'').removeClass("funjsq_disable2");
                                                $$('#plugin'+num+'').removeClass("funjsq_enable2");
                                                $$('#plugin'+num+'').addClass("active");
                                                $$('#circle'+num+'').css('display','block');
                                                $$('#fontStatus'+num+'').html("开启中");
                                                $$('#fontStatus'+num+'').css('color','gray');
                                                $$.progress_bar(num);
                                                setTimeout(function(){$$.updateStatus(select_mac);},2*1000);
                                        } else {
                                                //location.href = "funjsq_pay.htm";
                                                alert("请重试");
                                        }
                                }else{
                                        if ( json.status == "1" ) {
                                                //$$.checkStatus();
						$$.updateStatus(select_mac);
                                                //location.href = "funjsq_select.htm";
                                        } else {
                                                alert("无效的请求，请重试");
                                                //location.href = "funjsq_select.htm";
                                        }
                                }
			});
			return true;
		}

		$$('#resetBt2').click(function() {
                        var cf=document.forms[0];
                        cf.submit_flag.value="reset_plugin";
                        cf.action="/admin.cgi?/funjsq_select.htm timestamp="+ts;
                        $$.postForm('#selectNewForm', '', function(json) {
                                if ( json.status == "1" ) {
                                        //$$.checkStatus();
                                        location.href = "funjsq_select_new.htm";
                                } else {
                                        alert("无效的请求，请重试");
                                        //location.href = "funjsq_select.htm";
                                }
                        });
                        return true;
                });

		$$.progress_bar = function(num) {
                        if(progress == 90){
                                $$('#progress'+num+'').html("90%");
                                setTimeout(function(){
                                        $$('#circle'+num+'').css('display','none');
					$$('#plugin'+num+'').removeClass("funjsq_enable2");		
                                        $$('#plugin'+num+'').addClass("funjsq_disable2");
                                },1500);
                                $$('#resetBt2').trigger("click");
                                $$('#pluginBt'+num+'').val("open");
                        }else{
                                $$('#progress'+num+'').html(""+progress+"%");
                                progress = parseInt(progress)+10;
                        }
                }
	}

	if ( $$('#payForm').length ) {
		var suit_num;
		$$.getData('http://api.funjsq.com/thirdParty/netgear/SearchProductInfo.php?Mobile='+mobile+'',function(json){
			var i=0;
			if ( json.List.length > 0 ) {
				for ( i = 0; i < json.List.length; i++ ){
					if(json.List[i].ID == "181"){
						$$('#pay1').html(json.List[i].Price);
					}else if(json.List[i].ID == "184"){
						$$('#pay2').html(json.List[i].Price);						
					}else if(json.List[i].ID == "187"){
						$$('#pay3').html(json.List[i].Price);
					}else if(json.List[i].ID == "190"){
						$$('#pay4').html(json.List[i].Price);
					}
				}
				$$.selectSuit("1");
			}
			if( json.code == "1001")
				alert("用户不存在");
		},function(){});

		$$.chExpireTime = function(){
			var ExpireTime = $$('.pay').find('li.text').find('p:eq(1)').find('span:eq(0)').text();//console.log(ExpireTime);
			var TimeType = $$('.pay li:eq(0)').find('span.active').attr('data-fun-product');//console.log(T);
			var UseTime = $$('.pay li:eq(1)').find('span.active').attr('data-fun-product');
			if(TimeType !='' && TimeType != null && TimeType != undefined ){
				if(TimeType == 'd'){
					if(moment().isBefore(ExpireTime) != true){
						ExpireTime = moment().format('YYYY-MM-DD HH:mm:ss');
					}
					//console.log(ExpireTime);
					var newExpireTime=moment(ExpireTime,'YYYY-MM-DD HH:mm:ss').add(UseTime,'day').format('YYYY-MM-DD HH:mm:ss');
					$$('.pay').find('li.text').find('p:eq(1)').find('span:eq(1)').text(newExpireTime);
				}else if (TimeType == 'h'){
					if(moment().isBefore(ExpireTime) != true){
						ExpireTime = moment().format('YYYY-MM-DD HH:mm:ss');
					}
					//console.log(ExpireTime);
					var newExpireTime=moment(ExpireTime,'YYYY-MM-DD HH:mm:ss').add(UseTime,'hours').format('YYYY-MM-DD HH:mm:ss');
					$$('.pay').find('li.text').find('p:eq(1)').find('span:eq(1)').text(newExpireTime);
				}else{
					$$('.pay').find('li.text').find('p:eq(1)').find('span:eq(1)').text(ExpireTime);
				}
			}else{
				$$('.pay').find('li.text').find('p:eq(1)').find('span:eq(1)').text(ExpireTime);
			}
			$$.chPayAmount();
		}

		/**
		 * [chPayAmount 更改余额]
		 * @return   {[type]}                 [description]
		 * @Author   vincent
		 * @DateTime 2017-08-12T14:47:33+0800
		 */
		$$.chPayAmount = function(){
			var Amount= $$('.pay li:eq(1)').find('span.active').find('em').attr('data-fun-product');
			$$('.pay li:eq(4)').find('p:eq(1)').find('b').text(Amount);
		}

		$$('#payBt').click(function() {
			var id=suit_num*3 + 178;
			window.open("https://api.funjsq.com/thirdParty/netgear/zfb/alipayapi.php?Mobile="+mobile+"&ID="+id+"");
			$$('#payForm').css('display','none');
			$$('#confirmForm').css('display','block');
		});

		$$.selectSuit = function(num){
			suit_num = num;
			$$('#suit'+num+'').addClass("active");
			$$('.sum b').html($$('#pay'+num+'').html());	
			for(var j=1;j<5;j++){
				if(j != num)
					$$('#suit'+j+'').removeClass("active");
			}
			$$.chExpireTime();
		}

		$$('#suit1').trigger('click');

		$$('#payTrouble').click(function() {
			if(QQSupport== "" )
				alert("请加入帆游用户QQ群（492072361）");
			else
				alert("请加入帆游用户QQ群（"+QQSupport+"）");
			location.href="funjsq_select.htm";
		});

		$$('#payFinish').click(function() {
			var cf=document.forms[0];
			cf.action="/admin.cgi?/funjsq_pay.htm timestamp="+ts;
			$$('.plz_wait').css('display','block');	
			$$('#confirmForm').css('display','none');
			$$.postForm('#payForm', '', function(json) {
                                if ( json.code == "1000" ) {
					location.href="funjsq_select_new.htm";
				} else if(json.code == "1001"){
					alert(json.msg);
					$$('#payForm').css('display','block');
					$$('#confirmForm').css('display','none');
					$$('.plz_wait').css('display','none');
                                } else{
                                        alert("请检查你的网络连接。");
					$$('.plz_wait').css('display','none');
					$$('#payForm').css('display','block');
                                        $$('#confirmForm').css('display','none');
                                }
                        });
                });
	}

/*
function getPluginInfo() {
	$$.getData('plugin_info.aspx',function(json){
		if(json.funjsq_status == "1"){
			$$('#funjsq_icon2').removeClass("icon_fail");
			$$('#funjsq_icon2').removeClass("icon_start");
			$$('#funjsq_icon2').removeClass("icon_access");
			$$('#funjsq_icon2').addClass("icon_success");
			$$('.circleProgress_wrapper').css('display','none');
			$$('#status_info').html("加速成功");
			$$('#funjsqConntime').html(json.funjsq_conntime);
			$$('#funjsqIp').html(json.funjsq_ip);
			$$('#funjsqMac').html(json.funjsq_mac);
			setTimeout(function(){getPluginInfo();},1*1000);
		}else if (json.funjsq_status == "2"){
			$$('#funjsq_icon2').removeClass("icon_fail");
			$$('#funjsq_icon2').removeClass("icon_start");
			$$('#funjsq_icon2').removeClass("icon_success");
			$$('#funjsq_icon2').addClass("icon_access");
			$$('.circleProgress_wrapper').css('display','none');
			$$('#funjsqConntime').html(json.funjsq_conntime);
                        $$('#funjsqIp').html(json.funjsq_ip);
                        $$('#funjsqMac').html(json.funjsq_mac);
			setTimeout(function(){getPluginInfo();},1*1000);
			if( json.funjsq_accType == "1"){
				$$('#status_info').html("请在PS4中操作：[设定]-[网络]-[测试网络连线]");
				$$('#status_info2').html("如果测速失败，请尝试多测速几次");
			}
			else if ( json.funjsq_accType == "3"){
				$$('#status_info').html("请在Xbox中操作：[设置]-[网络设置]-[检查网络连线]");
				$$('#status_info2').html("如果测速失败，请尝试多测速几次");
			}
			else {
				$$('#status_info').html("请确保您的电脑与本路由器在同一网络");
			}
		}else if (json.funjsq_status == "7"){
			$$('#status_info').html("开启中");
			$$('#funjsq_icon2').removeClass("icon_fail");
			$$('#funjsq_icon2').removeClass("icon_success");
			$$('#funjsq_icon2').removeClass("icon_access");
			$$('.circleProgress_wrapper').css('display','block');
			progress_bar();
			//$$('#funjsq_icon2').addClass("icon_start");
			setTimeout(function(){getPluginInfo();},3*1000);
		}else if (json.funjsq_status == "0"){
			$$('#status_info').html("服务器未启动");
			$$('#funjsq_icon2').addClass("icon_fail");
			$$('#funjsq_icon2').removeClass("icon_start");
			$$('#funjsq_icon2').removeClass("icon_access");
			$$('#funjsq_icon2').removeClass("icon_success");
			$$('.circleProgress_wrapper').css('display','none');
			setTimeout(function(){getPluginInfo();},3*1000);
		}else {
			$$('#funjsq_icon2').addClass("icon_fail");
			$$('#funjsq_icon2').removeClass("icon_start");
			$$('#funjsq_icon2').removeClass("icon_access");
			$$('#funjsq_icon2').removeClass("icon_success");
			$$('.circleProgress_wrapper').css('display','none');
			if (json.funjsq_status == "3"){
				$$('#status_info').html("会员过期，请续费");
			}
			else if (json.funjsq_status == "6"){
				$$('#status_info').html("服务器启动失败，请检查网络状况");
				$$('#status_info2').html("请尝试更改路由器的DNS为233.5.5.5或者114.114.114.114");
			}
			else if (json.funjsq_status == "8"){
				$$('#status_info').html("操作异常，请重新开启插件");
			}
			else if (json.funjsq_status == "9"){
				$$('#status_info').html("后台插件升级成功，请重新开启插件");
			}
			else if (json.funjsq_status == "10"){
				$$('#status_info').html("网络抖动，服务已断线，请重新开启服务");
			}
		}
	});
}
*/

$$.checkStatus = function()
{
	$$.getData('plugin_info.aspx',function(json){
		if (json.funjsq_status != "0")
			setTimeout(function(){$$.checkStatus();},3*1000);
		else
			return true;
	});
}


}); // end ready function

}(jQuery));
