function myFunction() {
  var checkBox = document.getElementById("led1");
  if (checkBox.checked == true){
    firebase.database().ref('/LED/1').once('value', function(snapshot) {
	snapshot.forEach(function(snap) {
		name1.innerHTML = JSON.stringify(snap.val().ds, null, 1);
		const bt = "ON"
		const ds = 30
		data = {bt,ds}
		firebase.database().ref('/LED/1').update(data);
		console.log("Done")
		});
  });
  }
  else{
	firebase.database().ref('/LED/1').once('value', function(snapshot) {
	snapshot.forEach(function(snap) {
		name1.innerHTML = JSON.stringify(snap.val().ds, null, 1);
		const bt = "OFF"
		const ds = 10
		data = {bt,ds}
		firebase.database().ref('/LED/1').update(data);
		console.log("Done")
		});
  });
  }
}