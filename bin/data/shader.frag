#version 150
#extension GL_ARB_texture_rectangle:enable
out vec4 outputColor;

uniform float iTime;

uniform sampler3D tex3d;

uniform vec2 iResolution;
uniform vec2 iFrameSize;
float sdBox(in vec2 p,in vec2 b)
{
    vec2 d=abs(p)-b;
    return length(max(d,0.))+min(max(d.x,d.y),0.);
}
vec2 map(vec2 value,vec2 inMin,vec2 inMax,vec2 outMin,vec2 outMax){
    return outMin+(outMax-outMin)*(value-inMin)/(inMax-inMin);
}
mat2 r(float a){
    float c=cos(a),s=sin(a);
    return mat2(c,-s,s,c);
}
void main()
{
    vec2 uuv=gl_FragCoord.xy/iResolution;
    
    uuv.y=1.-uuv.y;
    vec2 uv=(gl_FragCoord.xy-.5*iResolution.xy)/iResolution.y;
        uv *=r(iTime*.1);
     //float b = uv.y*.5+sin(uv.x*.125-length(cos(uv*.2+iTime)))+iTime*.125;
     uv.x+=.15;
    float b=sin(floor(uv.y*10.5+iTime)/10.)+uv.x;
    b = sdBox(uv*r(floor(iTime+length(uv)*5.)),vec2(.5,.5)+iTime*.5);
   
    // b = length(uv)-floor(iTime)+pow(fract(iTime),.125)+.66;

    vec3  t=texture(tex3d,vec3(uuv,b)).rgb;
    float d=length(uv);
    outputColor=vec4(t,1.);
}