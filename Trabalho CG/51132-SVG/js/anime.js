"use strict;";
const oneSecond = 1000;

/*
Utility
*/

function get_transform(elem) {
  let item = elem.transform.baseVal.getItem(0);
  let m = item.matrix;
  return {
    x: m.e,
    y: m.f,
    sx: m.a,
    sy: m.d,
    a: item.angle,
  };
}

function set_transform(elem, t) {
  let item = elem.transform.baseVal.getItem(0);
  let m = item.matrix;
  if (t.hasOwnProperty("x")) m.e = t.x;
  if (t.hasOwnProperty("y")) m.f = t.y;
  if (t.hasOwnProperty("sx")) m.a = t.sx;
  if (t.hasOwnProperty("sy")) m.d = t.sy;
}

function popular_Arvores(elem) {
  popular_Arvores = () => {}; //matar a funçao quando chamada

  let groupElem = elem.getElementById("Background");
  let elementArv = elem.getElementById("arvore");
  let i = 1,
    x = 100;
  //console.log(elementArv);
  while (x * i < 1024) {
    let element = elementArv.cloneNode(true);
    let item = element.transform.baseVal.getItem(0);
    let m = item.matrix;
    m.e = x * i;
    element.attributes.id.value = "a" + i;
    //console.log(element.attributes.id);
    groupElem.appendChild(element);
    i++;
  }
  //console.log(groupElem);
}

//random number gen
const random = (max, min) => {
  return Math.random() * (max - min + 1) + min;
};

function waterDropSpawn(waterElem, nuvem, context) {
  let n = random(10, 5);
  let xDisplacement = random(100, 5);

  let origem = {
    x: get_transform(nuvem).x,
  };

  let xMin = origem.x - xDisplacement;
  let xMax = origem.x + xDisplacement;
  let divided = (xMax - xMin) / n;

  //for (let i = 0; i <= 0; i++) {
  xMin += divided;

  //copiar last element da coleção

  waterElem = waterElem.item(waterElem.length - 1);
  let waterElemCopy = waterElem.cloneNode(true);
  let xInicial = get_transform(waterElemCopy).x;
  xInicial = xInicial + xMax;

  let t = {
    x: xInicial,
  };
  set_transform(waterElemCopy, t);
  context.appendChild(waterElemCopy);
  return waterElemCopy;

  //let test = get_transform(newDrop);
  //console.log(test);
  //}
}

function anime_svg(elem) {
  let nuvem = elem.getElementById("nuvem_animate");

  let nuvem_anim = {
    from: {
      x: get_transform(nuvem).x,
    },
    target: {
      x: 910,
    },
    duration: 5500,
    easing: TWEEN.Easing.Quadratic.InOut,
    update_func: function (step) {
      set_transform(nuvem, { x: step.x });
    },
  };

  let waterGroup = elem.getElementsByClassName("pinga");
  let context = elem.getElementById("waterDroplets");
  let pinga = waterDropSpawn(waterGroup, nuvem, context);

  let pinga_anim = {
    from: {
      y: get_transform(pinga).x,
    },
    target: {
      y: 910,
    },
    duration: 5500,
    easing: TWEEN.Easing.Quadratic.InOut,
    update_func: function (step) {
      set_transform(pinga, { y: step.y });
    },
  };

  let nuvem_tween = make_tween(nuvem_anim).yoyo(true).repeat(1);
  let pinga_tween = make_tween(pinga_anim);
  nuvem_tween.start();
  pinga_tween.start();
  //nuvem_tween.start();
  //let cargo_tween = make_tween(cargo_anim).yoyo(true).repeat(1);
  //truck_tween.chain(cargo_tween).start();

  requestAnimationFrame(animation_loop);
}

function animation_loop(time) {
  requestAnimationFrame(animation_loop);
  TWEEN.update(time);
}

function make_tween(spec) {
  return new TWEEN.Tween(spec.from)
    .to(spec.target, spec.duration)
    .easing(spec.easing)
    .onUpdate(spec.update_func);
}

function main() {
  let svg_model = document.getElementById("SVGAnim").contentDocument;
  popular_Arvores(svg_model);
  //console.log(svg_model);
  anime_svg(svg_model);
}
