// 読み込んでないチャンクに対して処理をするためのテンプレ @babiron!


var HANI=15; // 自分を中心とした直径

var FLAG_CHANK={ // 端から何ブロックの場所をフラグとして管理するか
	x:4,
	z:7,
};


var AUTO_GENERATION=(function(){
	
	var _thread=null; // スレッドが入る
	
	var _flag=16; // チャンク操作の時に使う
	
	
	//=================================================================
	//
	//     _serch_chank関数
	//
	// 自分の周りのチャンクを検索して _chank_call_back 関数にチャンクの端の座標を渡す
	//
	//=================================================================
	
	function _serch_chank(ent){
		_chank_call_back(ent.x,ent.z);
		for(var i=1;i<=HANI;i++){
			for(var k=0;k<i;k++){
				ent.x+=_flag;
				_chank_call_back(ent.x,ent.z);
			}
			for(var k=0;k<i;k++){
				ent.z+=_flag;
				_chank_call_back(ent.x,ent.z);
			}
			
			flag=0-_flag;
		}
		
		for(var i=1;i<HANI;i++){
			ent.x+=_flag;
			_chank_call_back(ent.x,ent.z);
		}
	}
	
	
	//=================================================================
	//
	//       _chank_call_back関数
	//
	// 読み込んだチャンクの端の座標が渡される関数。
	// もう1回処理されないための処理の部分の下にチャンクに施したい処理を書けばいい
	//
	//=================================================================
	
	function _chank_call_back(x,z){
		// ===========  もう1回呼び出されないための処理  =============
		if(Level.getTile(x+FLAG_CHANK.x,0,z+FLAG_CHANK.z)==7 && Level.getData(x+FLAG_CHANK.x,0,z+FLAG_CHANK.z)==1)
			return;
		Level.setTile(x+FLAG_CHANK.x,0,z+FLAG_CHANK.z,7,1);
		// =================================================
		
		
		
		// =============  ここからチャンクに施す処理  ================
		
		
		
		
		
		// ==================================================
		
		_thread.sleep(1); // メモリリークで落ちるかもしれないから処理を制限
		
	}
	
	
	// ====================================================
	//
	//   _start_thread
	//
	// 呼び出すと自分の周りを HANI だけ読み込むスレッドを実行する.
	//
	// ====================================================
	
	function _start_thread(){
		if(_thread===null){
			try{
				
				// プレイヤーの座標の整数値
				var ent={
					x:Math.floor(Player.getX()),
					z:Math.floor(Player.getZ()),
				};
				
				ent.x=ent.x>>4;
				ent.x=ent.x<<4;
				ent.z=ent.z>>4;
				ent.z=ent.z<<4;
				
				
				_thread=new java.lang.Thread(new java.lang.Runnable({
					run:function(){
						try{
							
							_serch_chank(ent);
							
							_thread=null;
							
						}catch(err){
							print(err);
						}
					}
				}));
				_thread.setPriority(android.os.Process.THREAD_PRIORITY_BACKGROUND);
				_thread.setDaemon(true);
				_thread.start();
				
			}catch(err){
				clientMessage(err);
				_thread=null;
			}
		}
	}
	
	return {
		start_thread:_start_thread,
	};
	
})();
