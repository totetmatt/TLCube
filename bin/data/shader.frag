#version 150
#extension GL_ARB_texture_rectangle : enable 
out vec4 outputColor;

uniform float iTime;

uniform sampler3D tex3d;

uniform vec2 iResolution;
uniform vec2 iFrameSize;

vec2 map(vec2 value, vec2 inMin, vec2 inMax, vec2 outMin, vec2 outMax) {
  return outMin + (outMax - outMin) * (value - inMin) / (inMax - inMin);
}
mat2 r(float a){
    float c=cos(a),s=sin(a);
    return mat2(c,-s,s,c);
}
void main()
{
    vec2 uuv =  gl_FragCoord.xy/iResolution;
     
     uuv.y = 1.-uuv.y;
    vec2 uv = (gl_FragCoord.xy-.5*  iResolution.xy )/  iResolution.y;

    vec2 fuv = map(uv,vec2(-.5,.5),vec2(.5,-.5),vec2(0.,0.),iFrameSize);

    // vec3 t = texture(tex,fuv).rgb;
    //vec3 t = texture(tex,vec2(gl_FragCoord.x,iResolution.y- gl_FragCoord.y)*10. ).rgb;
    vec3 t = texture(tex3d, vec3(uuv,fract(uv.x+iTime))).rgb;
    float d = length(uv);
    outputColor = vec4(t,1.);
}