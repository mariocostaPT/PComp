/**
 * Creates an SVG element.
 *
 * The element is defined by an object with attributes:
 *
 * - tag: The element's tag (eg 'rect', 'svg', 'path').
 * - attributes (optional): The element's attributes (e.g 'x', 'fill').
 * - children (optional): list of sub-elements specifications.
 *
 * @param {object} spec - the specification of the svg element.
 */
function svg(spec) {
  let element = document.createElementNS(
    "http://www.w3.org/2000/svg",
    spec.tag
  );
  if (spec.hasOwnProperty("attributes")) {
    for (let attr in spec.attributes) {
      element.setAttributeNS(null, attr, spec.attributes[attr]);
    }
  }
  if (spec.hasOwnProperty("children")) {
    for (let child_spec of spec.children) {
      let child = svg(child_spec);
      element.appendChild(child);
    }
  }
  return element;
}

function main() {
  let svg_element = svg({
    tag: "svg",
    attributes: {
      width: 1680,
      height: 516,
    },
    children: [
      {
        id: "Terreno",
        tag: "rect",
        attributes: {
          x: 0,
          y: 466,
          width: 1680,
          height: 50,
          fill: "green",
        },
      },
      [
        {
          id: "Base Montanha",
          tag: "polygon",
          attributes: {
            points: "500,466 550,400 1000,400 1050,466",
            fill: "blue",
            stroke: "black",
          },
        },
      ],
    ],
  });

  let svg_container = document.getElementById("svg-container");
  svg_container.appendChild(svg_element);
  let src_container = document.getElementById("src-container");
  src_container.innerText = svg_element.outerHTML;
}

main();
